#include<cstdio>
#include<cstring>
const int maxn = 100010;
int hashFun(char* a,int len){
	int num = 0;
	for(int i=0;i<len;i++){
		num = 26*num+(*(a+i))-'a';
	}
	return num;
}
int main(){
	int hash[maxn] = {0};
	int m,n;
	char input[3];
	char search[3];
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%s",input);
		int id = hashFun(input,strlen(input));
		hash[id]++;
	}
	scanf("%d",&n);
	for(int j=0;j<n;j++){
		scanf("%s",search);
		int id_search = hashFun(search,strlen(search));
		printf("%d\n",hash[id_search]);
	}
}