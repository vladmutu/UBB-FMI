#include <stdio.h>

char concatenare(char sir1[], char sir2[], len1, len2);

int main()
{
    sir1 = ['a', '1', '2', 'b', '3'];
    sir2 = ['c', '4', 'd', 'e', '5'];
    rez = concatenare(sir1, sir2, 5, 5);
    printf("%s", rez);
    rez = concatenare(sir2, sir1, 5, 5);
    printf("%s", rez);
    return 0;
}