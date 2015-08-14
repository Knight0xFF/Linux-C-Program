#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char **argv)
{
    struct stat sta;
    if (argc != 2)
    {
        printf("args too less\n");
        exit(1);
    }
    if (access(argv[1], F_OK) != -1)
    {
        if (access(argv[1], R_OK) != -1)
        {
            printf("readable\n");
        }
        if (access(argv[1], W_OK) != -1)
        {
            printf("writeable\n");
        }
        if (access(argv[1], X_OK) != -1)
        {
            printf("execable\n");
        }
    }
    else
    {
        printf("%s not exit\n", argv[1]);
    }

    return 0;

}
