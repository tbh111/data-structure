// #include<stdio.h>
// #include<string.h>
// int main(){
// 	int N;
// 	int i;
// 	scanf("%d",&N);
// 	int score[2][N];
// 	int total[N];
// 	memset(total,0,N);
// 	while(i<N){
// 		scanf("%d %d",&(score[0][i]),&(score[1][i]));
// 		i++;
// 	}

// 	for(int k=0;k<N;k++){
// 		int num = score[0][k];
// 		int sc = score[1][k];
// 		total[num]+=sc;
// 		printf("%d\n%d\n",num,sc);
// 		printf("%d\n",total[num]);
// 	}



// }
#include <stdio.h>
const int maxnum = 100010;
int school[maxnum] = {0};

int main(){
	int n,id,score;
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		scanf("%d %d",&id,&score);
		school[id]+=score;
	}
	int MAX = 0,number_ = 0;
	for(int k=0;k<n;k++){
		if(school[k]>MAX){
			MAX = school[k];
			number_ = k;
		}
	}
	printf("score: %d , school: %d\n",MAX,number_);
}