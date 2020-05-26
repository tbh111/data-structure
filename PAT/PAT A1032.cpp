#include<cstdio>
const int maxn = 100010;
struct list
{
	int data;
	int next;
	bool flag;
	list(){
		flag = false;
	}
};
int main(){
	int n =0;
	int add1,add2;
	int ad,d,nx,p,q;
	list ls[maxn];
	scanf("%d %d %d ",&add1,&add2,&n);
	for(int i=0;i<n;i++){
		scanf("%d %d %d",&ad,&d,&nx);
		ls[ad].data = d;
		ls[ad].next = nx;
	}
	for(p=add1 ; p!=-1 ; p = ls[p].next){
		ls[p].flag = true;
	}
	for(q=add2;q!=-1;q = ls[q].next){
		if(ls[q].flag ==  true)
			break;
	}
	if(q != -1){
		printf("05%d\n",q);
	}
	else printf("-1");
	return 0;
}