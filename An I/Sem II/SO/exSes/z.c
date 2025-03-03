#include <unistd.h>
#include <stdio.h>

int main()
{
    execlp("expr", "expr", "a", "+", "1", NULL);
    printf("xyz\n");
    return 0;
}
