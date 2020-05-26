#include<stdio.h>
int main(){
	char a[10] = {3,6,1,7,2};
	for(int i=1;i<=4;i++){
		for(int j=0;j<5-i;j++){
			if(a[j+1]<a[j]){
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;

			}
		}
	}
	for(int k=0;k<5;k++){
		printf("%d",a[k]);
	}
}