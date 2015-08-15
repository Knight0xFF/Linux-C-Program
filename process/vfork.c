#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;
    int sta;
    char *arrArg[] = {"test", "A", "B", "C", NULL};
    char *arrEnv[] = {"env1=150", "env2=tom", NULL};
    pid = vfork();
    if (pid < 0)
    {
        printf("create process fail\n");
        exit(1);
    }
    if (pid == 0)
    {
        execve("./env", arrArg, arrEnv);
    }
    else
    {
        if (pid != wait(&sta))
        {
            printf("wait child error\n");
            exit(1);
        }
    }

    return 0;
}
