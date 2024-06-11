#include <fstream>
#include <iostream>
#include <climits>
using namespace std;

ifstream fin("in.txt");

int viz[105],a[50][50],n;

void dfs(int x)
{
    int i;
    viz[x]=1;
    for(i=1;i<=n;i++)
        if(a[x][i]==1 && viz[i]==0)
            dfs(i);
}

int main() {
    fin>>n;
    int x,y;
    while(fin>>x>>y)
    {
        a[x][y]=a[y][x]=1;
    }
    cout<<"nodurile izolate sunt: ";
    for(int i=1;i<=n;i++)
    {
        bool ok = true;
        for(int j=1;j<=n;j++)
            if(a[i][j]==1)
                ok = false;
        if(ok)
            cout<<i<<' ';
    }
    bool ok = true;
    int nr = 0;
    for(int i=1;i<=n;i++)
        if(a[i][1]==1)
            nr++;
    for(int i=2;i<=n;i++) {
        int k = 0;
        for (int j = 1; j <= n; j++)
            if (a[i][j] != 0)
                k++;
        if (k != nr)
        {
            ok = false;
            break;
        }
    }
    if(ok)
        cout<<"\ngraful este regular\n";
    else
        cout<<"\ngraful nu este regular\n";
    cout<<'\n';
    int dist[100][100]={0};
    for(int i=1;i<=99;i++)
        for(int j=1;j<=99;j++)
            if(i!=j)
                dist[i][j]=INT_MAX;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(a[i][j]!=0)
                dist[i][j]=1;

    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX)
                    if(dist[i][j]>dist[i][k]+dist[k][j])
                        dist[i][j] = dist[i][k]+dist[k][j];
    for(int i=1;i<=n;i++,cout<<endl)
        for(int j=1;j<=n;j++)
        {
            if(dist[i][j]==INT_MAX)
                cout<<"INF ";
            else
                cout<<dist[i][j]<<' ';
        }
    cout<<'\n';

    bool ok1=true;
    dfs(1);
    for(int i=1;i<=n;i++)
        if(viz[i]==0)
            ok1= false;
    if(ok1)
        cout<<"graful este conex";
    else
        cout<<"graful nu este conex";
    return 0;
}
