#include <iostream>
#include <fstream>
#define inf 10000000
int a[1005][1005];
int c[1005][1005];
int V,E,x,y,w,s;
int d[1005];
void init()
{
    for(int i=0;i<V;i++)
        d[i]=inf;
}

void bellman_ford(int nod)
{
    init();
    d[nod]=0;
    for(int i=0;i<V-1;i++)
        for(int j=0;j<V;j++)
            for(int k=0;k<V;k++)
                if(a[j][k]==1)
                    if(d[k]>d[j]+c[j][k])
                        d[k]=d[j]+c[j][k];
}

int main(int argc, char *argv[]) {
    std::ifstream in(argv[1]);
    std::ofstream out(argv[2]);

    in>>V;
    in>>E;
    in>>s;
    for(int i = 1; i <= E; i++)
    {
        in>>x>>y>>w;
        a[x][y]=1;
        c[x][y]=w;
    }
    bellman_ford(s);
    for(int i=0;i<V;i++)
        if(d[i]!=inf)
            out<<d[i]<<' ';
        else
            out<<"inf ";
    return 0;
}
