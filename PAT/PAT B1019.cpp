#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn= 10000;
bool cmp_up(int a,int b){
	return a>b;
}
bool cmp_dowm(int a,int b){
	return a<b;
}
int arrayToNum(int a[]){
	return (a[0]*1000+a[1]*100+a[2]*10+a[3]);
}
int fun(int a){
	int number1 = a;
	int num_arr[4] = {};
	for(int i=0;i<4;i++){
		num_arr[i] = a%10;
		a/=10;
		// printf("%d\n",num_arr[i]);
	}
	if(num_arr[0]==num_arr[1]&&num_arr[2]==num_arr[3]&&num_arr[1]==num_arr[2]){
		printf("%04d-%04d=0\n",number1,number1);
		return -1;
	}

	else{
		int up[4];
		int down[4];

		for(int i=0;i<4;i++){
			up[i]=num_arr[i];
			down[i]=num_arr[i];
		}

		sort(up,up+4,cmp_up);
		sort(down,down+4,cmp_dowm);
		// for(int i=0;i<4;i++){
		// 	printf("%d\n",down[i]);
		// }
		int up_num = arrayToNum(up);
		int down_num = arrayToNum(down);
		printf("%d-%d=%d\n",up_num,down_num,up_num-down_num);
		return up_num-down_num;
	}
}
int main(){
	int number = 0;
	scanf("%d",&number);
	while(1){
		
		number = fun(number);
		if(number == -1||number == 6174)
			break;
	}
	






	}
