#include <cstdio>
#include <cstdlib>

struct BINode{
    char data;
    BINode* lchild;
    BINode* rchild;
};

void CreateBT(BINode* &T){
    
    char ch;
    scanf("%c",&ch);
    if(ch == '#'){
        T = NULL;
    }
    
    else{
        T = (BINode*)malloc(sizeof(BINode));
        T->data = ch;
        CreateBT(T->lchild);
        CreateBT(T->rchild);
    }

}

void preOrder(BINode* ptr){
    
    if(ptr!=NULL)
    {
        printf("%c",ptr->data);
        preOrder(ptr->lchild);
        preOrder(ptr->rchild);
    }
}

void ExchangeBT(BINode* &T){
    
    if(T != NULL){

    
        BINode* tmp = T->lchild;
        T->lchild = T->rchild;
        T->rchild = tmp;
        ExchangeBT(T->lchild);
        ExchangeBT(T->rchild);
        
    }
}

BINode* find_x(BINode* T,char x){
    BINode* tmp;
    if(T != NULL){
        if(T->data == x)
            return T;
        tmp = find_x(T->lchild,x);
        if(tmp == NULL)
            tmp = find_x(T->rchild,x);
        return tmp;
    }
    return NULL;
}


void CountLeaf(BINode* T,int &count){
    if(T != NULL){
        if((T->lchild == NULL) && (T->rchild == NULL)){
            count++;
        }
        CountLeaf(T->lchild,count);
        CountLeaf(T->rchild,count);
    }
}

void DispBiTree(BINode* T,int level){
    if(T != NULL){
        DispBiTree(T->rchild, level+1);
        for(int i=0;i<level;i++)
            printf("#");
        printf("%c\n",T->data);
        DispBiTree(T->lchild, level+1);
    }
}

int main() {
    int count = 0;
    BINode* n = (BINode*)malloc(sizeof(BINode));
    printf("input: ");
    CreateBT(n);
    preOrder(n);
    printf("\n");
    
    printf("display bitree\n");
    DispBiTree(n, 0);
    
    BINode* x = find_x(n,'A');
    CountLeaf(x, count);
    printf("count = %d\n",count);
    
    ExchangeBT(n);
    preOrder(n);
    printf("\n");
    
    return 0;
}
