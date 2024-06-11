#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("graf.txt");

int a[50][50],viz[50][50], sol[50];
int n;

void bfs(int nod, int nr, int &lgmin)
{
    int count = 0;
    for(int i = 0; i <= n; i++)
    {
        if(a[nod][i] and viz[nod][i] == 0)
        {
            sol[nr] = i;
            viz[nod][i] = 1;
            bfs(i, nr+1, lgmin);
            viz[nod][i] = 0;
            count++;
        }
    }
    if (count == 0 and (lgmin == -1 or nr < lgmin))
        lgmin = nr;
}
int main()
{
    int x , y, i, vf, mini = -1;
    fin >> n;
    while (fin >> x >> y)
        a[x][y] = 1;
    cout<<"Varful sursa:\n";
    cin >> vf;
    cout << '\n';
    cout << "Cel mai scurt lant este: " << vf << " ";
    bfs(vf,0,mini);
    for(i = 0; i < mini; i++)
        cout << sol[i] << " ";
    return 0;
}