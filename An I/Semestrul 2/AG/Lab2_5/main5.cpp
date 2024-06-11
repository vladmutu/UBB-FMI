#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("input.txt");

int viz[101],a[101][101],n;

void dfs(int nod)
{
    for(int i=1;i<=n;i++)
        if(!viz[i] && a[nod][i])
        {
            cout << i << " ";
            viz[i] = 1;
            dfs(i);
        }
}

int main()
{
    int x,y;
    fin >> n;
    while(fin >> x >> y)
    {
        a[x][y] = 1;
    }

    int nod;
    cout<<"Introduceti nodul sursa:";
    cin >> nod;
    dfs(nod);

    return 0;
}