//
// Created by 曾强 on 15/11/3.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char **argv)
{
    int ret;
    pid_t pid;
    union sigval sg;

    if (argc != 2)
    {
        printf("args error\n");
        exit(1);
    }
    pid = atoi(argv[1]);
    sg.sival_int = getpid();
    ret = sig(pid, SIGUSR1, sg);

    if (ret != 0)
    {
        printf("Send error\n");
    }
    else
    {
        printf("Done!\n");
    }

    return 0;
}
