#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

void newthread(void)
{
    int i, res;
    res = pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);

    res = pthread_setcancelstate(PTHREAD_CANCEL_DEFERRED, NULL);

    for (i = 0; i < 5; i++)
    {
        printf("new thread\n");
        sleep(1);
    }
    pthread_exit("thread exit!\n");
}

int main()
{
    pthread_t pth;
    int res;
    void *pth_result;

    res = pthread_create(&pth, NULL, (void *)newthread, NULL);

    if (res != 0)
    {
        printf("create thread fail\n");
        exit(1);
    }

    sleep(2);
    printf("cancel thread\n");
    res = pthread_cancel(pth);
    if (res != 0)
    {
        printf("cancel fail\n");
        exit(1);
    }

    return 0;
}
