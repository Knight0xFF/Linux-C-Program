#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    int i;
    for (i = 0; i < argc; i++)
    {
        printf("arg%d: %s\n", i, argv[i]);
    }
    char **penv = __environ;
    while (penv && *penv)
    {
        printf("%s\n", *penv++);
    }

    return 0;
}
