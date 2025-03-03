#include <stdio.h>
#include <stdbool.h>

bool este_prim(int n) {
    if(n < 2)
        return false;
    if(n != 2 && n % 2 == 0)
        return false;
    for(int d = 3; d * d <= n; d += 2)
        if(n % d == 0)
            return false;
    return true;
}

int main() {
    int n;
    scanf_s("%d", &n);
    printf("%d\n", n);
    bool este_prim_n = este_prim(n);
    if(este_prim_n)
        printf("Numarul este prim");
    else
        printf("Numarul nu este prim");


    /*char nume[6];
    int size = 6;
    scanf_s("%5s", nume, 6);
    printf("Nume: %s", nume);*/
}
