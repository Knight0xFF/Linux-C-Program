#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sched.h>


struct sched_param
{
    int __sched_priority;
};

void newthread(void)
{
    printf("newthread is running\n");
    sleep(3);
    printf("newthread is running\n");
    pthread_exit(NULL);

}

int main()
{
    pthread_t pth;
    pthread_attr_t attr;
    sched_param param;
    int res;

    res = pthread_attr_init(&attr);
    if (res)
    {
        printf("set thread fail\n");
        exit(1);
    }

    res = pthread_attr_getschedstate(&attr, &param);
    if (res)
    {
        printf("get sched fail\n");
        exit(1);
    }

    param.sched_priority = newprio;
    res = pthread_attr_setschedparam(&thread_attr,&param);
    if (res)
    {
        printf("set sched fail\n");
        exot(1);
    }

    res = pthread_create(&pth, &attr, (void *)newthread, NULL);

    if (res)
    {
        printf("create thread fail\n");
        exit(1);
    }

    return 0;
}
