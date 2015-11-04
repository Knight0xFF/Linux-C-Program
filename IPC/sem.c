//
// Created by 曾强 on 15/11/4.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/wait.h>

int main()
{
    int semid;
    int i, ret, sta;
    pid_t pid;
    key_t key;
    struct sembuf lock = {0, -1, SEM_UNDO};
    struct sembuf unlock = {0, 1, SEM_UNDO | IPC_NOWAIT};

    key = ftok("/Users/xiaobai/shadowsocks.json", 'b');

    semid = semget(key, 1, IPC_CREAT | 0666);
    if (semid < 0)
    {
        perror("semget error");
        exit(1);
    }

    ret = semctl(semid, 0, SETVAL, 1);
    if (ret < 0)
    {
        perror("semctl error");
        exit(1);
    }

    pid = fork();
    if (pid < 0)
    {
        printf("fork error\n");
        exit(1);
    }
    if (pid == 0)
    {
        for (i = 0; i < 3; i++)
        {
            sleep(abs((int)(3.0*rand()/(RAND_MAX+1.0))));
            ret = semop(semid, &lock, 1);
            if (ret == -1)
            {
                perror("lock error");
                exit(1);
            }
            printf("Child process access the resources\n");

            sleep(abs((int)(3.0*rand()/(RAND_MAX+1.0))));
            printf("Complete!\n");

            ret = semop(semid, &unlock, 1);
            if (ret == -1)
            {
                perror("unlock error");
                exit(1);
            }
        }
    }
    else
    {
        for (i = 0; i < 3; i++)
        {
            sleep(abs((int)(3.0*rand()/(RAND_MAX+1.0))));
            ret = semop(semid, &lock, 1);
            if (ret == -1)
            {
                perror("lock error");
                exit(1);
            }
            printf("Parent process access the resources\n");

            sleep(abs((int)(3.0*rand()/(RAND_MAX+1.0))));
            printf("Complete!\n");

            ret = semop(semid, &unlock, 1);
            if (ret == -1)
            {
                perror("unlock error");
                exit(1);
            }
        }
        if (pid != wait(&sta))
        {
            printf("wait error\n");
            exit(1);
        }
        ret = semctl(semid, 0, IPC_RMID, 0);
        if (ret == -1)
        {
            perror("semctl error");
            exit(1);
        }
    }
    return 0;
}