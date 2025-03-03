#include <unistd.h>
#include <stdlib.h>


int main()
{
    if(fork() != fork())
        fork();
    sleep(10);
    return 0;
}
