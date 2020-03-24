#include<cstdio>
#include<cstdlib>
struct node
{
	int data;
	int number;
	node* next;
	// node* pre;
};


node* create(int n, int pwd[]){//初始化
	node* head = (node*)malloc(sizeof(node));
	if(head == NULL) exit(1);
	node* tail;
	int count = 0;
	head->data = pwd[0];
	head->number = count;
	head->next = head;
	node* p = head;
	// printf("%d\n",head->next->data);
	for(int i=1;i<n;i++){
		node* new_node = (node*)malloc(sizeof(node));
		new_node->data = pwd[i];
		new_node->number = ++count;
		p->next = new_node;
		// new_node->next = head;
		p = new_node;
	}
	tail = p;
	p->next = head;
	return head;
}

void print_list(node* a){//打印一组链表
	node* b = a;
	do{
		printf("number:%d data:%d\n",b->number,b->data);
		b = b->next;
	}
	while(b!=a);
}

void del(node* n){//删除n节点的后一个节点
	// printf("delete number:%d data:%d\n",n->next->number,n->next->data);
	node* p = n->next;
	n->next = p->next;
	free(p);
}

int* loop(node* n, int m, int sequence[]){//主循环
	// while(n->next!=n){
	// 	del(n);
	// }
	// int count = 0;
	int total = 0;
	while(n->next!=n){
		int count = 1;
		while((count+1)!=m){
			count++;
			n = n->next;
		}
		node* choice = n->next;

		m = choice->data;
		sequence[total] = (choice->number)+1;
		// printf("choose number %d with data %d\n",sequence[total],m);
		node* tmp = n;
		n = choice->next;
		del(tmp);
		// printf("total:%d\n", total);
		total++;

	}
	sequence[total] = (n->number)+1;
	return sequence;
}

int main(){
	int n, m;
	node* p;
	printf("input n\n");
	scanf("%d",&n);
	printf("input m\n");
	scanf("%d",&m);
	int* password = (int*)malloc(sizeof(int)*n);
	int* seq = (int*)malloc(sizeof(int)*n);
	printf("input %d password\n",n);
	for(int i=0;i<n;i++){
		scanf("%d",(password+i));
	}

	printf("processing..\n");
	p = create(n,password);
	// print_list(p);
	node* q = p;
	int*a = loop(p,m,seq);
	printf("result: ");
	for(int i=0;i<n;i++){
		printf("%d ",*(a+i));
	}
	printf("\n");
	return 0;

}