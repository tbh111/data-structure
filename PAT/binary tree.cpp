#include<cstdio>
struct node
{
	int data;
	node* left;
	node* right;	
};

node* newNode(int n){
	node* newnode = new node;
	newnode->data = n;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

void search(node* root,int x,int newdata){
	if(root == NULL)
		return;
	if(root->data == x)
		root->data = newdata;
	search(root->left,x,newdata);
	search(root->right,x,newdata);
}

void insert(node* &root,int x){
	if(root == NULL){
		root = newNode(x);
		return;
	}
	
		insert(root->left,x);
		insert(root->right,x);
	
	
}

node* create(int A[], int n){
	node* root = NULL;
	for(int i = 0;i<n;i++){
		insert(root,A[i]);
	}
	return root;
}

void preorder(node* root){
	if(root == NULL){
		return;
	}
	printf("%d\n",root->data);
	preorder(root->left);
	preorder(root->right);
}

int main()
{
	int A[5]={0,1,2,3,4};
	node* tree = create(A,10);
	preorder(tree);
	return 0;
}