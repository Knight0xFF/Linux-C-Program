#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t tim;
    time(&tim);
    printf("%s\n", ctime(&tim));

    return 0;
}
