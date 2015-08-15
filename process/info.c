#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;
    int sta;
    pid = fork();
    if (pid < 0)
    {
        printf("fork error\n");
        exit(1);
    }
    if (pid == 0)
    {
        printf("Child Process: \n");
        printf("pid = %d\n", getpid());
        printf("ppid = %d\n", getppid());
        printf("gid = %d\n", getpgrp());
        exit(1);
    }
    else
    {
        printf("Parent Process: \n");
        printf("pid = %d\n", getpid());
        printf("ppid = %d\n", getppid());
        printf("gid = %d\n", getpgrp());
        if (pid != wait(&sta))
        {
            printf("wait error\n");
            exit(1);
        }
    }
    return 0;
}
