#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100010;

struct Node
{
	int data;
	int next;
	int address;
	bool flag;
	Node(){
		flag = false;
	}
}node[maxn];

bool cmp(Node a,Node b){
	if(a.flag == false || b.flag == false){
		return a.flag > b.flag;
	}
	else return a.data > b.data;
}

int main(){
	int N,head;
	int ad,dt,nx;
	scanf("%d %d",&N,&head);
	for(int i=0;i<N;i++){
		scanf("%d %d %d",&ad,&dt,&nx);
		node[ad].data = dt;
		node[ad].next = nx;
		node[ad].address = ad;
	}
	int p,count;
	for(p=head;p!=-1;p=node[p].next){
		node[p].flag = true;
		count++;
	}
	if(p == -1){
		printf("0 -1");
	}
	else{
		sort(node,node+maxn,cmp);
		printf("%d %05d\n",count,node[p].address);
		for(int i=0;i<count;i++){
			if(i!=count-1){
				printf("%05d %d %05d",node[i].address,node[i].data,node[i+1].address);
			}
			else printf("%05d %d -1",node[i].address,node[i].data);
		}
	}
}