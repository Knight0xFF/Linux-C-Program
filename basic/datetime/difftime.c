#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#define SIZE 100000

int main()
{
    time_t start;
    time_t stop;
    int i, j;
    int *p;
    double res;
    time(&start);
    for (i = 0; i < 90000; i++)
    {
        p = (int *)malloc(SIZE*sizeof(int));
        for (j = 0; j < SIZE; j++)
        {
            *(p + j) = j;
        }
        free(p);
    }
    time(&stop);
    res = difftime(stop, start);
    printf("%f\n", res);

    return 0;
}
