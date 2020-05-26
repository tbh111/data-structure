#include<algorithm>
#include<stdio.h>
#include<string.h>
using namespace std;
struct Stu
{
	char number[14];
	int score;
	int local_rank;
	int location;
}stu[1000];
bool cmp(Stu a,Stu b){
	if(a.score!=b.score) return (a.score>b.score);
	else return (strcmp(a.number,b.number)<0);
}
int main(){
	int K,N;//N考场数 K考生数
	int i=0,j=0;
	int num = 0;
	scanf("%d",&N);
	

	for(int i=1;i<=N;i++){
		scanf("%d",&K);
		for(int j=0;j<K;j++){
			scanf("%s %d",(stu[num].number),&(stu[num].score));
			stu[num].location = i;
			num++;
		}
		sort(stu+num-j,stu+num,cmp);
		stu[num-j].local_rank = 1;
		for(int a=num-j+1;a<num;a++){
			if(stu[a].score==stu[a-1].score){
				stu[a].local_rank = stu[a-1].local_rank;
			}
		else stu[a].local_rank = a+1-(num-j);
		}
	
	}
	printf("%d\n",num);
	sort(stu,stu+num,cmp);
	int r = 1;
	for(int i=0;i<num;i++){
		if(i>0&&stu[i].score!=stu[i-1].score){
			r=i+1;
		}
		printf("%s ",stu[i].number);
		printf("%d %d %d\n",r,stu[i].location,stu[i].local_rank);
	}


}