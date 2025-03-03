#include <stdio.h>

int main(int argc, char* argv[]) {
    int m=3,n=2,a[3][2];
    for(int i= 0 ;i<m;i++)
        for(int j = 0; j<n;j++)
            scanf("%d", *(a+i)+j);
    for(int i = 0; i<m;i++)
        for(int j = 0; j< n;j++)
            if(*(*(a+i)+j)>=4)
                printf("%d ", 1+*(*(a+i)+j));
            else
                printf("%d ", 2**(*(a+i)+j));
    return 0;
}
