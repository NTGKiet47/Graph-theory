#include<stdio.h>
#define MAX 100
#define INF 9999999
typedef struct{
	int ar_graph[MAX][MAX];
	int n;
}Graph;
void init_graph(Graph *g, int n){
	int i, j;
	g->n = n;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			g->ar_graph[i][j] = -1;
}
void add_edge(Graph *g, int x, int y, int w){
	g->ar_graph[x][y] = w;
	g->ar_graph[y][x] = w;
}
void moore_dijktra(Graph g, int start, int end){
	int pi[MAX], mark[MAX];
	int i, j, k, min_pi = INF;
	for(i=1;i<=g.n;i++){
		pi[i] = INF;
		mark[i] = 0;
	}
	pi[start] = 0;
	for(i=1;i<=g.n;i++){
		min_pi = INF;
		for(j=1;j<=g.n;j++){
			if(pi[j] < min_pi && mark[j]==0){
				min_pi = pi[j];
				k = j;
			}
		}
		mark[k] = 1;
		for(j=1;j<=g.n;j++){
			if(g.ar_graph[k][j]!=-1 && mark[j]==0){
				if(g.ar_graph[k][j] + pi[k] < pi[j]){
					pi[j] = g.ar_graph[k][j] + pi[k];
				}
			}
		}
	}
	if(pi[end]==INF){
		printf("-1");
	}else
		printf("%d", pi[end]);
}
int main(){
	
	int n, m ,x,y,w;
	scanf("%d%d", &n, &m);
	Graph g;
	init_graph(&g, n);
	while(m--){
		scanf("%d%d%d", &x, &y, &w);
		add_edge(&g, x, y, w);
	}
	int s, e;
	scanf("%d%d", &s, &e);
	moore_dijktra(g, s, e);	
	return 0;
}
