#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;
    int sta;
    int i = -1;
    pid = fork();
    if (pid < 0)
    {
        printf("create child process fail\n");
        exit(1);
    }
    if (pid == 0)
    {
        printf("This is a child process\n");
    }
    else
    {
        sleep(1);
        printf("This is a parent process\n");
        printf("waiting for child process...\n");
        if (pid != wait(&sta))
        {
            printf("wait error\n");
            exit(1);
        }
        if (WIFEXITED(sta))
        {
            i = WEXITSTATUS(sta);
        }
        printf("child pid = %d\n", pid);
        printf("exit status =%d\n", i);
    }

    return 0;
}

