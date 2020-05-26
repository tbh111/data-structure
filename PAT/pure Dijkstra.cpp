#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1000;
const int INF = 1000000000;

int dot,side,start,G[maxn][maxn];
int dis[maxn];//start to each point distance
bool visited[maxn] = {false};
int pre[maxn];
void dijkstra(int start){
	fill(dis,dis+maxn,INF);
	dis[start] = 0;
	for(int i = 0;i<dot;i++){
		int u = -1, MIN = INF;
		for(int j = 0;j<dot;j++){
			if(visited[j] == false && dis[j]<MIN){
				u = j;
				MIN = dis[j];
			}
		}
		if(u == -1) return;
		visited[u] = true;
		for(int v = 0;v<dot;v++){
			if(visited[v] == false && G[u][v] != INF && dis[u]+G[u][v]<dis[v]){
				dis[v] = dis[u]+G[u][v];
				pre[v] = u;
			}
		}
	}
}
void DFS(int start,int v){
	if(v == start){
		printf("%d\n",start);
		return;
	}
	else{
		DFS(start,pre[v]);
		printf("%d\n",v);
	}

}
int main(){
	int u,v,w;
	scanf("%d %d %d",&dot,&side,&start);
	fill(G[0],G[0]+maxn*maxn,INF);
	for(int i = 0;i<side;i++){
		scanf("%d %d %d",&u,&v,&w);
		G[u][v] = w;
	}
	dijkstra(start);
	for(int j = 0;j<dot;j++){
		printf("%d\n",dis[j]);
	}
	DFS(start,pre[0]);
	return 0;
}