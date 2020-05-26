#include <stdio.h>
int main(){
	int arr[5]={1,2,6,3,7};
	for(int i=0;i<4;i++){
		int minIndex = i;
		for(int j=i+1;j<5;j++){
			if(arr[j]<arr[minIndex]){
				minIndex = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = temp;
	}
	for(int k=0;k<5;k++){
		printf("%d ", arr[k]);
	}
}