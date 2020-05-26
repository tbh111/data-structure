#include<cstdio>
int main(){
	int array[10];
	int number[8];
	// scanf("%d %d %d %d %d %d %d %d %d %d",&array[0],&array[1],&array[2],&array[3],&array[4],&array[5],&array[6],&array[7],&array[8],&array[9]);
	for(int i=0;i<10;i++){
		scanf("%d",array+i);
	}
	for(int i=1;i<10;i++){
		if(array[i]!=0){
			number[0] = i;
			array[i]-=1;
			// printf("%d\n",i);
			break;
		}
	}
	for(int j=1;j<8;j++){
		for(int k=0;k<10;k++){
			if(array[k]!=0){
				number[j] = k;
				array[k]-=1;
				break;
			}
		}
	}

		
	
	for(int i=0;i<8;i++){
		printf("%d",number[i]);
	}
}