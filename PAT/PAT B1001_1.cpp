#include<stdio.h>
void judge(int a){
	int count=0;
	int n =a;
	while(n!=1){
		
		if((n%2)==0){
			n=n/2;
			count++;
		}
		else{
			n=(3*n+1)/2;
			count++;
		}
	}
	printf("number: %d , total: %d\n",a,count);

}
int main(){
	for(int i=2;i<10000;i++){
		judge(i);
	}
	return 0;
}