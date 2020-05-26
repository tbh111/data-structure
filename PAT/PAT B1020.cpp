#include<cstdio>
#include<algorithm>
using namespace std;
// int main(){
// 	int N,D;//N->type D->need
// 	scanf("%d %d",&N,&D);
// 	double money[N];
// 	double store[N];
// 	double ave_money[N];

// 	for(int i=0;i<N;i++){
// 		scanf("%lf",store+i);
// 	}
// 	for(int i=0;i<N;i++){
// 		scanf("%lf",money+i);
// 		ave_money[i] = money[i]/store[i];
// 		printf("%f\n",ave_money[i]);
// 	}
// 	double max = 0;
// 	for(int i=0;i<N;i++){
// 		if(ave_money[i]>max) 
// 			max = ave_money[i];
// 	}


// }
struct mooncake
{
	double money;
	double store;
	double ave_money;
}cake[1010];

bool cmp(mooncake a,mooncake b){
	return a.ave_money>b.ave_money;
}

int main(){
	int N,D;
	double income = 0;
	scanf("%d %d",&N,&D);
	for(int i=0;i<N;i++){
		scanf("%lf",&(cake[i].store));
	}
	for(int i=0;i<N;i++){
		scanf("%lf",&(cake[i].money));
		cake[i].ave_money = cake[i].money/cake[i].store;
	}
	sort(cake,cake+N,cmp);
	for(int i=0;i<N;i++){
		if(cake[i].store<=D){
			D-=cake[i].store;
			income+=cake[i].money;
		}
		else{
			income+=D*cake[i].ave_money;
			break;
		}
	}
	
	printf("%.2f\n",income);
	// for(int i=0;i<N;i++)
	// 	printf("%f\n",cake[i].ave_money);
}