//
// Created by 曾强 on 15/11/2.
//

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define BUFSIZE 256

int main(int argc, char **argv)
{
    pid_t cpid;
    FILE *fp;
    int fifod[2];  // fifod[0]为读端，fifod[1]为写端
    int sta;
    char buf[BUFSIZE] = "Linux C\n";
    if (pipe(fifod) < 0)
    {
        printf("pipe error.\n");
        exit(1);
    }
    cpid = fork();
    if (cpid < 0)
    {
        printf("fork error.\n");
        exit(1);
    }
    if (cpid == 0)
    {
        fp = fopen(argv[1], "r");
        if (fp == NULL)
        {
            perror("open file error");
            exit(1);
        }
        while (fgets(buf, sizeof(buf), fp) != NULL)
        {
            close(fifod[0]);
            write(fifod[1], buf, sizeof(buf));
        }
        fclose(fp);
        strcpy(buf, "`");
        close(fifod[0]);
        write(fifod[1], buf, sizeof(buf));
    }
    else
    {
        fp = fopen(argv[2], "w");
        if (fp == NULL)
        {
            perror("open write file error");
            exit(1);
        }
        close(fifod[1]);
        read(fifod[0], buf, sizeof(buf));
        while ('`' != buf[0])
        {
            fputs(buf, fp);
            close(fifod[1]);
            read(fifod[0], buf, sizeof(buf));
        }
        fclose(fp);
    }

    return 0;
}
