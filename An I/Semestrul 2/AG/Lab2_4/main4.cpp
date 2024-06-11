#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("graf.txt");

int viz[101],a[101][101],n;
int Coada[1001],inc,sf;

void bfs(int nod)
{
    inc = 0;
    Coada[sf++] = nod;
    int d = 1;
    viz[nod] = 1;
    while(sf != inc)
    {

        for(int i=1;i<=n;i++)
            if(a[Coada[inc]][i] && !viz[i])
            {
                cout << i << " " << d << endl;
                Coada[sf++] = i;
                viz[i] = 1;
            }

        inc++;
        d++;
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
    bfs(nod);

    return 0;
}