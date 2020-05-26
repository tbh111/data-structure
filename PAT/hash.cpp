#include<cstdio>
const int maxn =100010;
int hash[maxn] = {0};
int main(){
	int m,n,x;
	printf("input m\n"); 
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d",&x);
		hash[x]++;

	}
	printf("input search n\n");
	scanf("%d",&n);
	for(int j=0;j<n;j++){
		scanf("%d",&x);
		printf("%d\n",hash[x]);
	}
}