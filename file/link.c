#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <error.h>

int main(int argc, char **argv)
{
    int lik;
    if (argc != 3)
    {
        printf("args too less\n");
        exit(1);
    }
    lik = symlink(argv[1], argv[2]);
    if (lik == -1)
    {
        perror("create link fail\n");
        exit(1);
    }
    printf("done!\n");

    return 0;
}
