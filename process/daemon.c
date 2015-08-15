#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#define FILESIZE 1024

int main()
{
    pid_t pid;
    FILE *fp;
    int i;
    char *buf = "This is a example process\n";
    pid = fork();
    if (pid < 0)
    {
        printf("create child process fail\n");
        exit(1);
    }
    if (pid > 0)
    {
        exit(0);
    }
    setsid();
    for (i = 0; i < FILESIZE; i++)
    {
        close(i);
    }
    chdir("/tmp");
    umask(0);
    signal(SIGCHLD, SIG_IGN);
    while (1)
    {
        fp = fopen("/tmp/test", "a");
        if (fp == NULL)
        {
            perror("open test file fail\n");
            exit(1);
        }
        fputs(buf, fp);
        fclose(fp);
        sleep(3);
    }

    return 0;
}
