#include<cstdio>
#include<cstdlib>
#include<string>
#define Maxn 100
using namespace std;

struct stack
{
    char* base;
    char* top;
    int stacksize;
};

stack* init_stack(){
    stack* s = (stack*)malloc(Maxn * sizeof(stack));
    s->base = (char*)malloc(Maxn * sizeof(char));
    if(!s->base){
        printf("init err\n");
        exit(1);
    }
    s->top = s->base;
    s->stacksize = Maxn;
    return s;
}

bool is_Empty(stack* s){
    if(s->top == s->base){
        return true;
    }
    else
        return false;
}

void push(stack* s, char data){
    if((s->top - s->base) >= s->stacksize){
        printf("overflow");
        s->base = (char*)realloc(s->base,(s->stacksize+Maxn)*sizeof(char));
        if(!s->base){
            printf("push err\n");
            exit(1);}
    s->top = s->base + s->stacksize;
    s->stacksize += Maxn;
    }
    *(++s->top) = data;
    printf("push %c on top\n",*(s->top));
}

char pop(stack* s){
    if(is_Empty(s)){
        printf("pop err\n");
        exit(1);
    }
    char data;
    data = *(s->top);
    printf("pop: %c\n",data);
    s->top--;

    return data;
}

char cmp(char op1, char op2){
    int i=0,j=0;
    char map[7][7] = {
        {'>','>','<','<','<','>','>'},
        {'>','>','<','<','<','>','>'},
        {'>','>','>','>','<','>','>'},
        {'>','>','>','>','<','>','>'},
        {'<','<','<','<','<','=','0'},
        {'>','>','>','>','0','>','>'},
        {'<','<','<','<','<','0','='}
    };

    switch(op1){
        case '+': i=0; break;
        case '-': i=1; break;
        case '*': i=2; break;
        case '/': i=3; break;
        case '(': i=4; break;
        case ')': i=5; break;
        case '#': i=6; break;

    }
    switch(op2){
        case '+': j=0; break;
        case '-': j=1; break;
        case '*': j=2; break;
        case '/': j=3; break;
        case '(': j=4; break;
        case ')': j=5; break;
        case '#': j=6; break;
}
    return map[i][j];
    
}

void print_stack(stack* s){
    char* tmp = s->top;
    while(*(tmp--)){
        printf("%c\n",*(tmp--));
    }
}

stack* change(string str){
    stack* op = init_stack();//操作符
    stack* num = init_stack();//后缀式
    char OP;
    push(op, '#');
    printf("Init %c\n",*(op->top));

    for(int i=0;i<str.length();i++){
        if(str[i] >='a' && str[i] <='z'){
            printf("read num %c\n",str[i]);
            push(num,str[i]);
        }
        else if(str[i] == '('){
            printf("find (\n");
            push(op,str[i]);
        }
        else if(str[i] == ')'){
            printf("find )\n");
            while(*(op->top)!='('){
                OP = pop(op);
                push(num,OP);
            }
            char tmp = pop(op);
            printf(" pop %c\n",tmp);
            
        }
        else{
            printf("\n");
            printf("compare %c,%c\n",*(op->top),str[i]);

            if(cmp(*(op->top),str[i]) == '<'){
                printf("case < : push %c\n",str[i]);
                push(op,str[i]);
                printf("\n");
            }
            else{
                printf("case >\n");

                while(cmp(*(op->top),str[i]) != '<' && !is_Empty(op))
                {
                    push(num,pop(op));
                }
                push(op,str[i]);
            }
        }
    }

    while(!is_Empty(op) && *(op->top)!='#'){
        OP = pop(op);
        push(num,OP);
    }
    free(op);
    return num;
}


int main(){

    string st = "a+b/c-(d*e+f)*g";
    st = st + '#';
    stack* s = change(st);

    printf("\n");

    while(!is_Empty(s)){
        printf("%c",*(s->base++));
    }
    printf("\n");
    free(s);
    return 0;
}


