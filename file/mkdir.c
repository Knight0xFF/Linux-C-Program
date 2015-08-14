#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <error.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char **argv)
{
    int res;
    if (argc != 2)
    {
        printf("args too less\n");
        exit(1);
    }
    res = mkdir(argv[1], S_IRUSR | S_IXUSR);
    if (res == -1)
    {
        perror("mkdir fail\n");
        exit(1);
    }
    printf("done!\n");

    return 0;
}
