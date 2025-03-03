#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("input.txt");

int n,m,a[101][101],x,y;
int coada[1001],inceput,sfarsit;

int sol[101][101];

int main()
{
    fin >> n;
    while(fin >> x >> y)
    {
        a[x][y] = 1;
    }

    for(int i=1;i<=n;i++)
    {
        inceput = 0;
        coada[0] = i;
        sfarsit = 1;

        while(sfarsit > inceput)
        {
            int nod = coada[inceput];
            inceput++;
            for(int j=1;j<=n;j++)
                if(a[nod][j] == 1 && sol[i][j] == 0)
                {
                    coada[sfarsit] = j;
                    sfarsit++;
                    sol[i][j] = 1;
                }
        }
    }

    for(int i=1;i<=n;i++)
    {
        cout<<"Varful "<<i<<" -> ";
        for(int j=1;j<=n;j++) {
            if (i == j)
                sol[i][j] = 0;
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}