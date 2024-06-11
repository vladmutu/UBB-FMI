#include <stdio.h>
#include <stdbool.h>
#include <math.h>


//functie de verificare a primalitatii a unui numar
//x sa fie intreg
//preconditii: x intreg
//input: int
//postconditii: sa returneze true daca e prim si altfel false
//output: bool
bool prim(int x)
{
    if(x < 2)
        return false;
    if(x % 2 == 0 && x != 2)
        return false;
    for(int i = 3; i <= sqrt(x); i += 2)
        if(x % i == 0)
            return false;
    return true;
}

//functie de generare a numerelor prime mai mici sau egale decat un numar dat ca parametru
//x sa fie intreg
//preconditii: x intreg > 1
//input: int
//postconditii: numerele afisate sa fie prime si mai mici decat x
//output: None
void generare_prime(int x)
{
    for(int i=2; i <= x; i++)
        if(prim(i))
            printf("%d ", i);
    printf("\n");
}

//functie recursiva de generare a tuturor posibilitatilor de a scrie numarul n ca suma de numere consecutive
//n int
//preconditii - n>0
//postconditii - sa afiseze linii de numere consecutive
void suma_2(int n)
{
    for(int i=1;i<=n/2;i++)
    {
        int sp = 0;
        int sol[100] = {0};
        int k = 1;
        for(int j=i;j<=n/2; j++)
        {
            sp+=j;
            sol[k] = j;
            if(sp == n)
            {
                for (int p = 1; p <= k; p++)
                    printf("%d, ", sol[p]);
                printf("\n");
            }
            k++;
        }
    }
}

//functie main
//implementam meniul
int main() {
    int cmd;
    bool run = true;
    while(run)
    {
        printf("1.Genereaza numerele prime mai mici decat un numar\n");
        printf("2.Determina toate reprezentarile posibile a unui numar natural ca suma\n"
               "   de numere naturale consecutive\n");
        printf("0.Iesire aplicatie\n");
        printf("Introduceti comanda:");
        scanf("%d", &cmd);
        if(cmd == 0)
            run = false;
        else
            if(cmd == 1)
            {
                int nr;
                printf("Introduceti numarul:");
                scanf("%d", &nr);
                if(nr <= 1)
                    printf("Nu exista numere prime mai mici decat %d\n", nr);
                else
                    generare_prime(nr);
            }
            else
                if(cmd == 2)
                {
                    int n;
                    printf("Introduceti numarul:");
                    scanf("%d", &n);
                    if(n<3)
                        printf("Nu se poate scrie ca suma de numere consecutive pozitive");
                    else
                        suma_2(n);
                }
    }
    return 0;
}
