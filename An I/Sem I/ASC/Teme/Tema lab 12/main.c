#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char sir1[]={'a', 'b', '1', 'c', '2'};
char sir2[]={'d', 'e', 'f', '3', '4'};

int esteCifra(char);

void concatenare(char rez[], char sir1[], char sir2[])
{
    int k=0;
    for(int i=0;i<=strlen(sir1)-1;i++)
    {
        if(esteCifra(sir1[i]) == 1)
        {
            rez[k]=sir1[i];
            k++;
        }
    }
    for(int i=0;i<=strlen(sir2)-1;i++)
    {
        if(esteCifra(sir2[i]) == 1)
        {
            rez[k]=sir2[i];
            k++;
        }
    }
}


int main()
{
    int i;    
    char rez[20]={' '};
    concatenare(rez,sir1,sir2);
    for(i=0; i<=strlen(rez)-1;i++)
        printf("%c ", rez[i]);
    printf("%c", 10, 13, 0);
    concatenare(rez,sir2,sir1);
    for(i=0; i<=strlen(rez)-1;i++)
        printf("%c ", rez[i]);
    return 0;
}
