#include <cstdio>
#include <cmath>
const int maxn = 100010;
struct factor
{
	int x,cnt;
}fac[10];

bool p[maxn] = {0};
int prime[maxn];

void find_prime(int n){//筛选法选出n个素数
	int num = 0;
	for(int i=2;i<maxn;i++){
		if(p[i]==false){
			prime[num] = i;
			num++;
			if(num>n)
				break;
			for(int j=i+i;j<maxn;j+=i) p[j]=true;
		}
	}
}

// void find_prime_violent(int n){//暴力搜索
// 	int num = 0;
// 	while(num<n){
// 		for(int i=2;i<maxn;i++){
// 			for(int j=2;j<int(sqrt(i));j++){
// 				if(i%j == 0){
// 					p[i] = false;
// 					break;
// 				}
// 				else{
// 					p[i] = true;
// 					prime[num++] = i;
// 				}
// 			}
// 		}
// 	}
// }
bool isPrime(int n){
	if(n<=1) return false;
	for(int i=2;i<=int(sqrt(1.0*n));i++){
		if(n%i == 0){
			return false;
		}
	}
	return true;
	
}
int count = 0;
void find_prime_violent(int n){
	
	
	for(int i=1;i<maxn;i++){
		if(isPrime(i)){
			prime[count++] = i;
			}
		if(count>n) break;
	}
	
}
int num_fac = 0;
int main(){
	int number;
	scanf("%d",&number);
	int sqr = (int)sqrt(1.0*number);
	find_prime_violent(sqr);
	for(int i=0;i<=count&&prime[i]<sqr;i++){
		if(number%prime[i] == 0){
			fac[num_fac].x = prime[i];
			fac[num_fac].cnt = 0;
			while(number%prime[i]==0){
				fac[num_fac].cnt++;
				number/=prime[i];
			}
			num_fac++;
		}
		if(number==1) break;
		else{
			fac[num_fac].x = number;
			fac[num_fac].cnt = 1;
			num_fac++;
		}


	}

	for(int i=0;i<num_fac;i++){
		if(i>0) printf("*");
		printf("%d",fac[i].x);
		if(fac[i].cnt>1){
			printf("^%d",fac[i].cnt);
		}
	}









}