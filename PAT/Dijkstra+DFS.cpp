#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn = 1000;
const int INF = 1000000000;
int node,road;
vector<int> pre[maxn];
int dis[maxn],G[maxn][maxn];
bool visited[maxn] = {false};

void Dijkstra(int start){
	fill(dis,dis+maxn,INF);
	dis[start] = 0;
	for(int i=0;i<node;i++){
		int u = -1,MIN = INF;
		for(int j=0;j<node;j++){
			if(visited[j] == false && dis[j]<MIN){
				u = j;
				MIN = dis[j];
			}
		}
		if(u == -1) return;
		visited[u] = true;
		for(int v = 0;v<node;v++){
			if(visited[v] == false && G[u][v]!=INF){
				if(dis[u]+G[u][v]<dis[v]){
					dis[v] = dis[u]+G[u][v];
					pre[v].clear;
					pre[v].push_back(u);
				}
				else if(dis[u]+G[u][v] = dis[v]){
					pre[v].push_back(u);
				}
			}
		}
	}
}