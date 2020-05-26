#include<cstdio>
#include<stdlib.h>

struct node{
	int data;
	node* next;
};

node* create(int* a){
	node* head = new node;
	head->next = NULL;
	node* pre = head;
	for(int i = 0;i<10;i++){
		node* cur = new node;
		cur->data = *(a+i);
		cur->next = NULL;
		pre->next = cur;
		pre = cur;
	}
	return head;
}

int search(node* head,int n){
	int count = 0;
	node* p = head->next;
	while(p!=NULL){
		if(p->data == n){
			count++;
		}
		p = p->next;
	}
	return count;
}

node* insert(node* head,int pos,int num){
	int count = 0;
	node* p = head;
	
	
	while(count<pos-1){
		count++;
		p = p->next;
	}
	node* in = new node;
	in->data = num;
	in->next = p->next;
	p->next = in;
	return head;
}

void del_pos(node* head,int pos){

}

int main(){
	// int* p = (int*)malloc(sizeof(int));
	// node* q = (node*)malloc(sizeof(node));//get one node
	// free(p);
	// free(q);
	// int* a = new int;
	// node* b = new node;
	// delete(a);
	// delete(b);
	int arr[10];
	for(int i = 0;i<10;i++){
		arr[i] = i;
	}
	node* list = create(&arr[0]);
	list = list->next;

	while(list!=NULL){
		printf("%d\n",list->data);
		list = list->next;
	}
	list = insert(list,3,8);
	while(list!=NULL){
		printf("%d\n",list->data);
		list = list->next;
	}
}