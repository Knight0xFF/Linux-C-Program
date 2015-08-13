#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int a;
    for (a = 0; a < argc; a++)
    {
        printf("Argument %d is %s.\n", a, argv[a]);
    }

    return 0;

}
