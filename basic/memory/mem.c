#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int main()
{
    int *p;
    int i, tol;
    p = (int *)malloc(SIZE*sizeof(int));
    if (p == NULL)
    {
        printf("malloc error\n");
    }
    else
    {
        tol = 0;
        for (i = 0; i < SIZE; i++)
        {
            *(p + i) = i;
            printf("%d\n", p[i]);
            tol += p[i];
        }
        free(p);
    }
    printf("tol = %d\n", tol);
}
