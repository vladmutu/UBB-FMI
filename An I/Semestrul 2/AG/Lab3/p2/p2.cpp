#include <iostream>
#include <fstream>
#define inf 100000000
int V,E,x,y,w;
int a[1005][1005];
int c[1005][1005];
int d[1005];


void init()
{
    for(int i=0;i<V;i++)
        d[i]=inf;
}

bool bellman_ford(int nod)
{
    init();
    d[nod]=0;
    for(int i=0;i<V-1;i++)
        for(int j=0;j<V;j++)
            for(int k=0;k<V;k++)
                if(a[j][k]==1 && d[j]!=inf)
                    if(d[k]>d[j]+c[j][k])
                        d[k]=d[j]+c[j][k];
    for(int j=0;j<V;j++)
        for(int k=0;k<V;k++)
            if(a[j][k]==1 && d[j]!=inf)
                if(d[k]>d[j]+c[j][k])
                    return false;
    return true;
}

void dijkstra(int src) {
    bool visited[V];
    for(int i = 0; i < V; i++) {
        d[i] = inf;
        visited[i] = false;
    }
    d[src] = 0;
    for(int i = 0; i < V; i++) {
        int u = -1;
        for(int j = 0; j < V; j++) {
            if(!visited[j] && (u == -1 || d[j] < d[u])) {
                u = j;
            }
        }
        if(d[u] == inf) {
            break;
        }
        visited[u] = true;
        for(int v = 0; v < V; v++) {
            if(a[u][v] && d[v] > d[u] + c[u][v]) {
                d[v] = d[u] + c[u][v];
            }
        }
    }
}

int main(int argc, char *argv[]) {
    std::ifstream in(argv[1]);
    std::ofstream out(argv[2]);

    in >> V;
    in >> E;
    for (int i = 1; i <= E; i++) {
        in >> x >> y >> w;
        a[x][y] = 1;
        c[x][y] = w;
    }
}

