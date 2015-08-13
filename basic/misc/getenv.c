#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *p;
    p = getenv("SHELL");
    if (p == NULL)
    {
        printf("getenv error\n");
        exit(1);
    }
    else
    {
        printf("SHELL=%s\n", p);
    }

    return 0;

}
