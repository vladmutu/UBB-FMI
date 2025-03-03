#include <fstream>
#include <iostream>
using namespace std;

ifstream fin("in.txt");

int main() {
    int n,x,y;
    fin>>n;
    int a[50][50] = {0}, inc[50][105]={0}, l[50][105]={0};
    cout<<"matrice de adiacenta:\n";
    while(fin>>x>>y)
    {
        a[x][y]=a[y][x]=1;
    }
    for(int i=1;i<=n;i++,cout<<endl)
        for(int j=1;j<=n;j++)
            cout<<a[i][j]<<' ';

    cout<<"\nlista de adiacenta:\n";
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(a[i][j]!=0)
                l[i][j]=j;
        }
    for(int i=1;i<=n;i++)
    {
        cout << i << "---->";
        for (int j = 1; j <= n; j++) {
            if (l[i][j] != 0)
                cout<<j<<' ';
        }
        cout<<'\n';
    }

    cout<<"\nmatrice de incidenta:\n";
    int k=1;//numarul de muchii
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(l[i][j]!=0)
            {
                bool ok=true;
                for(int p=1;p<=n*(n-1)/2;p++)
                    if(inc[i][p]==inc[j][p] && inc[i][p]==1)
                        ok=false;
                if(ok)
                {
                    inc[j][k] = 1;
                    inc[i][k++] = 1;
                }
            }
    k--;
    for(int i=1;i<=k;i++)
        cout<<"m"<<i<<' ';
    cout<<endl;
    for(int i=1;i<=n;i++,cout<<endl)
        for(int j=1;j<=k;j++)
            cout<<inc[i][j]<<"  ";
    int l1[50][105]={0};
    cout<<"\nlista de adiacenta:\n";
    for(int i=1;i<=k;i++)
    {
        int prim = 0;
        for (int j = 1; j <= n; j++)
        {
            if(inc[j][i]!=0)
            {
                if(prim==0)
                    prim=j;
                else
                {
                    l1[j][prim]=prim;
                    l1[prim][j]=j;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout << i << "---->";
        for (int j = 1; j <= n; j++) {
            if (l1[i][j] != 0)
                cout<<j<<' ';
        }
        cout<<'\n';
    }
    cout<<endl;

    int a1[50][50]={0};
    cout<<"matrice de adiacenta:\n";
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(l[i][j]!=0)
                a1[i][l[i][j]]=a[l[i][j]][i]=1;
    for(int i=1;i<=n;i++,cout<<endl)
        for(int j=1;j<=n;j++)
            cout<<a1[i][j]<<' ';

    cout<<"\nlista:\n";
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            if(a1[i][j]!=0)
                cout<<i<<' '<<j<<'\n';
    return 0;
}
