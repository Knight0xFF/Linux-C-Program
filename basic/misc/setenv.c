#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    char *p;
    if (argc != 3)
    {
        printf("no arguments\n");
        exit(1);
    }
    if ((p = getenv(argv[1])) == NULL)
    {
        printf("%s does not exit\n", argv[1]);
    }
    else
    {
        printf("%s=%s\n", argv[1], p);
    }
    setenv(argv[1],argv[2], 1);
    if ((p=getenv(argv[1])) != NULL)
    {
        printf("%s=%s\n", argv[1], p);
    }

    return 0;
}
