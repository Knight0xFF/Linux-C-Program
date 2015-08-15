#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int i = 1;

void child_process()
{
    printf("child: %d, i = %d\n", getpid(), i);
    i++;
    printf("child: %d, i = %d\n", getpid(), i);
}

int main()
{
    pid_t pid;
    int sta;
    pid = fork();
    if (pid < 0)
    {
        printf("create child process fail\n");
        exit(1);
    }

    if (pid == 0)
    {
        child_process();
    }
    else
    {
        sleep(1);
        printf("parent: %d, i = %d\n", getpid(), i);
        if (pid != wait(&sta))
        {
            printf("waiting for child error\n");
            exit(1);
        }
    }

    return 0;
}
