#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <syslog.h>
#define FILESIZE 1024

int main()
{
    pid_t pid;
    time_t now;
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
    syslog(LOG_USER | LOG_INFO, "Daemon test!\n");
    while (1)
    {
        time(&now);
        syslog(LOG_USER | LOG_INFO, "now is : \t%d\t\t\n", ctime(&now));
        sleep(3);
    }

}
