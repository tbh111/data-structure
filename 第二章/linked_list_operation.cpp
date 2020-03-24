#include<cstdio>
#include<cstdlib>

struct node
{
	int data;
	node* next;
};

node* insertAtHead(int n,int num1[]){
	node* head = (node*)malloc(sizeof(node));
	if(head == NULL) exit(1);
	head->next = NULL;
	for(int i=0;i<n;i++){
		node* p = (node*)malloc(sizeof(node));
		p->data = num1[i];
		p->next = head->next;
		head->next = p;
	}
	return head;
}

node* insertAtTail(int m,int num2[]){
	node* head = (node*)malloc(sizeof(node));
	if(head == NULL) exit(1);
	head->next = NULL;
	node* tail = head;
	for(int i=0;i<m;i++){
		node* p = (node*)malloc(sizeof(node));
		p->data = num2[i];
		tail->next = p;
		p->next = NULL;
		tail = p;
	}
	return head;
}

void printList(node* list){
	node* tmp = list->next;//不打印头节点
	while(tmp != NULL){
		printf("%d ",tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}

node* reverseList(node* list){
	node* p = list->next;
	node* q;
	list->next = NULL;
	while(p != NULL){
		q = p;
		p = p->next;
		q->next = list->next;
		list->next = q;
	}
	return list;
}



node* mergeList(node* La, node* Lb, node* Lc){
	node* pa,* pb,* pc,* ptr;
	pa = La->next;
	pb = Lb->next;
	Lc = pc = La;
	while(pa && pb){
		if(pa->data > pb->data){
			pc->next = pb;
			pc = pb;
			pb = pb->next;
			}
		else if(pa->data < pb->data){
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
			ptr = pb;
			pb = pb->next;
			free(ptr);
		}
	}
	pc->next = pa? pa:pb;
	free(Lb);
	return Lc;
 }

node* delOdd(node* list){
	node* p = list;
	node* tmp;
	while(p->next != NULL){
		
		if(p->next->data %2 == 0){
			p = p->next;
		}
		else{
			tmp = p->next;
			p->next = tmp->next;
			free(tmp);
		}
	}
	return list;
}

int main(){

	int n, m;
	
	printf("input n\n");
	scanf("%d",&n);
	int* num1 = (int*)malloc(sizeof(int)*n);
	printf("input %d numbers\n",n);
	for(int i=0;i<n;i++){
		scanf("%d",(num1+i));
	}

	printf("input m\n");
	scanf("%d",&m);
	int* num2 = (int*)malloc(sizeof(int)*m);
	printf("input %d numbers\n",m);
	for(int j=0;j<m;j++){
		scanf("%d",(num2+j));
	}

	node* La = insertAtHead(n,num1);
	printf("La : ");
	printList(La);
	
	node* Lb = insertAtTail(m,num2);
	printf("Lb : ");
	printList(Lb);

	node* La_re = reverseList(La);
	printf("reversed La : ");
	printList(La_re);

	node* Lc = (node*)malloc(sizeof(node));
	Lc = mergeList(La_re,Lb,Lc);
	printf("Lc : ");
	printList(Lc);
	
	node* even = delOdd(Lc);
	printf("delete odd in Lc : ");
	printList(even);

	return 0;

}