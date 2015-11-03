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
    return;
}

int main()
{
    int ret;
    struct sigaction act;
    act.sa_sigaction = sig_handler;
    sigemptyset(&act.sa_mask);
    act.sa_flags = SA_SIGINFO;

    ret = sigaction(SIGINT, &act, NULL);
    if (ret != 0)
    {
        printf("sigaciont error\n");
        exit(1);
    }
    for (;;);

    return 0;
}