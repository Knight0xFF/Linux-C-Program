//
// Created by 曾强 on 15/11/3.
//

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sig_handler(int sig, siginfo_t *info, void *t)
{
    printf("Received signal: %d\n", sig);
    printf("Received message: %d\n", info->si_pid);
    return;
}

int main()
{
    int ret;
    pid_t pid;
    struct sigaction act;

    pid = getpid();
    act.sa_sigaction = sig_handler;
    sigemptyset(&act.sa_mask);
    act.sa_flags = SA_SIGINFO;

    ret = sigaction(SIGUSR1, &act, NULL);
    if (ret != 0)
    {
        printf("sigaciont error\n");
        exit(1);
    }
    printf("Recevied:\n");
    printf("PID: %d\n", pid);
    for (;;);

    return 0;
}