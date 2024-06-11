#include <iostream>
#include <fstream>
using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

int a[105][105], d[105], p[105];
int x,y,pondere;
int nr_noduri=-1;

void relax(int u, int v)
{
    if(d[v] > d[u] + a[u][v])
    {
        d[v] = d[u] + a[u][v];
        p[v] = u;
    }

}

void afiseaza_drumul(int nod_sursa)
{
    if(p[nod_sursa] != 0)
        afiseaza_drumul(p[nod_sursa]);
    cout<< nod_sursa << " ";
}

void bellman_ford(int nod_sursa)
{
    for(int i=1; i<=nr_noduri; i++)
    {
        d[i] = 999999;
    }
    d[nod_sursa] = 0;
    for(int k = 1; k <= nr_noduri; k++)
        for(int i = 1; i <=nr_noduri; i++)
            for(int j = 1; j <=nr_noduri; j++)
                if(a[i][j])
                    relax(i,j);
    for(int i = 1; i <=nr_noduri; i++)
        for(int j = 1; j <=nr_noduri; j++)
            if(a[i][j])
                if(d[j] > d[i] + a[i][j])
                {
                    cout<<"Ciclu negativ!\n";
                    return;
                }
    cout<<endl;
    for(int i=1; i<=nr_noduri; i++)
        if(d[i] != 999999)
        {
            cout<<"Drumul minim de la "<<nod_sursa<<" la "<<i<<" este: " <<d[i]<< endl;
            cout<<"si trece prin: ";
            afiseaza_drumul(i);
            cout<<endl;
        }
        else
            cout<<"Nu exista drum de la "<<nod_sursa<<" la "<<i<<endl;
}

int main() {
    int nod_sursa;
    int k=1;
    while( in >> x >> y >> pondere)
    {
        a[x][y] = pondere;
        if(x>nr_noduri)
            nr_noduri=x;
        if(y>nr_noduri)
            nr_noduri=y;
    }
    cout<<"Introduceti nodul sursa:";
    cin>>nod_sursa;
    bellman_ford(nod_sursa);
    return 0;
}
