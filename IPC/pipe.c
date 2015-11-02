#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#define BUFSIZE 256

int main()
{
    pid_t cpid;
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
        close(fifod[0]);
        write(fifod[1], buf, sizeof(buf));
    }
    else
    {
        close(fifod[1]);
        read(fifod[0], buf, sizeof(buf));
        printf("Received message from child process: \n%s", buf);
        if (cpid = wait(&sta))
        {
            printf("wait error.\n");
            exit(1);
        }
    }

    return 0;
}
