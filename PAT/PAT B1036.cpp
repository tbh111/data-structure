#include<stdio.h>
int main(){
	int N;
	char c;
	scanf("%d %c",&N,&c);
	// printf("%d\n%c\n",N,c);
	char square[N][N];
	int flag;
	if(N%2==0){
		flag = N/2;
	}
	else{
		flag = (N/2)+1;
	}
	for(int i=0;i<=flag;i++){
		if((i==0)||(i==flag)){
			for(int j=0;j<N;j++){
				square[i][j]=c;
			}
		}
		else{
			for(int j=0;j<N;j++){
				if((j==0)||(j==(N-1))){
					square[i][j]=c;
				}
				else{
					square[i][j]=' ';
				}
			}

		}
	}
	for(int row=0;row<N;row++){
		for(int col=0;col<N;col++){
			printf("%c",square[row][col]);
		}
		printf("\n");
	}
}