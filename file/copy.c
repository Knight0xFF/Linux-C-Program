#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <error.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define SIZE 256

int main(int argc, char **argv)
{
    int fol1, fol2;
    int cpy, wri;
    char buffer[SIZE];
    char *ptr;

    if (argc != 3)
    {
        printf("args too less\n");
        exit(1);
    }
    fol1 = open(argv[1], O_RDONLY);
    if (fol1 == -1)
    {
        perror("open file1 fail\n");
        exit(1);
    }
    fol2 = open(argv[2], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);

    if (fol2 == -1)
    {
        perror("open file2 fail\n");
        exit(1);
    }
    while ((cpy = read(fol1, buffer, SIZE)) != 0)
    {
        if (cpy == -1)
        {
            perror("read fail\n");
            break;
        }
        else if (cpy > 0)
        {
            ptr = buffer;
            while ((wri = write(fol2, ptr, wri)) != 0)
            {
                if (wri == -1)
                {
                    perror("write fail\n");
                    exit(1);
                }
                else if (wri == cpy)
                    break;
                else if (wri > 0)
                {
                    ptr += wri;
                    cpy -= wri;
                }
            }
            if (wri == -1)
                break;
        }
    }
    close(fol1);
    close(fol2);
    printf("done!\n");

    return 0;
}
