#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int pthflag = 0;

void newthread(void)
{
    printf("newthread is running\n");
    sleep(3);
    printf("newthread is running\n");
    pthflag = 1;
    pthread_exit(NULL);

}

int main()
{
    pthread_t pth;
    pthread_attr_t attr;
    int res;

    res = pthread_attr_init(&attr);
    if (res)
    {
        printf("set thread fail\n");
        exit(1);
    }

    res = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    if (res)
    {
        printf("set detach fail\n");
        exit(1);
    }

    res = pthread_create(&pth, &attr, (void *)newthread, NULL);

    if (res)
    {
        printf("create thread fail\n");
        exit(1);
    }

    while (!pthflag)
    {
        printf("wating for thread\n");
        sleep(1);
    }

    printf("thread already done\n");

    return 0;
}
