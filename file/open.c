#include <stdio.h>
#include <stdlib.h>
#include <error.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main()
{
    int fol;
    fol = open("file.txt", O_CREAT | O_EXCL, 00750);
    if (fol == -1)
    {
        perror("file open fail\n");

        exit(1);
    }

    return 0;
}
