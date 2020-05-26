#include<cstdio>
#include<cstring>
const int maxn = 100010;
const int mod = 1000000007;
int main(){
	char str[maxn];
	gets(str);
	int len = strlen(str);
	// printf("%d\n",len);
	int left[maxn] = {0};
	for(int i=0;i<len;i++){
		if(i>0)
			left[i] = left[i-1];
		if(str[i] == 'P')
			left[i]++;
	}

	int sum=0,right=0;
	for(int i=len-1;i>=0;i--){
		if(str[i] == 'T')
			right++;
		else if(str[i] == 'A'){
			sum = (sum+left[i]*right)%mod;
		}

	}
	printf("%d\n",sum);
}