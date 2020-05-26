#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1000;
const int INF = 100000000;

int node,road,start,ending;
int graph[maxn][maxn];
int dis[maxn],weight[maxn],num[maxn],w[maxn];
bool visited[maxn] = {false};

void dijkstra(int start){
	fill(dis,dis+maxn,INF);
	dis[start] = 0;
	weight[start] = 0;
	num[start] = 0;
	for(int i=0;i<node;i++){
		int u = -1,MIN = INF;
		for(int j=0;j<node;j++){
			if(visited[j] == false && dis[j] < MIN){
				u = j;
				MIN = dis[j];
			}
		}
		if(u == -1) return;
		visited[u] = true;
		for(int v=0;v<node;v++){
			if(visited[v] == false && graph[u][v] != INF){
				if(dis[u]+graph[u][v]<dis[v]){
					dis[v] = dis[u]+graph[u][v];
					w[v] = w[u]+weight[v];
					num[v] = num[u];
				}
				else if(dis[u]+graph[u][v] == dis[v]){
					if(w[u]+weight[v]>w[v]){
						w[v] = w[u]+weight[v];

					}
					num[v] += num[u];
				}
			}
		}
	}
}

int main(){
	
	fill(graph[0],graph[0]+maxn*maxn,INF);
	scanf("%d%d%d%d",&node,&road,&start,&ending);
	for(int i=0;i<node;i++){
		scanf("%d",&weight[i]);
	}
	int u,v;
	for(int j=0;j<road;j++){
		scanf("%d%d%d",&u,&v,&graph[u][v]);
		graph[v][u] = graph[u][v];
	}

	dijkstra(start);
	printf("%d %d\n",num[ending],w[ending]);
	return 0;




}