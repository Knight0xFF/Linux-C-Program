#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

void newthread(void)
{
    int i;
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

    int i;
    for (i = 0; i < 5; i++)
    {
        printf("main thread\n");
        sleep(1);
    }
    pthread_join(pth, &pth_result);
    printf("thread return: %s", (char *)pth_result);

    return 0;
}
