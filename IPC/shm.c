//
// Created by 曾强 on 15/11/4.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h> 
#define SHM_SIZE 1024
#define TIME_OUT 2

int main(int argc, char **argv)
{
    int shmid;
    key_t key;
    pid_t pid;
    int psm;
    struct shmid_ds ds_buf;

    if (argc != 2)
    {
        printf("args error\n");
        exit(1);
    }

    key = ftok("/Users/xiaobai/shadowsocks.json", 'b');
    if (key < 0)
    {
        perror("ftok error");
        exit(1);
    }

    shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid < 0)
    {
        perror("shmid error");
        exit(1);
    }

    pid = fork();
    if (pid < 0)
    {
        printf("fork error");
        exit(1);
    }

    if (pid == 0)
    {
        printf("Child process:\n");
        printf("PID: %d\n", getpid());
        psm  = (int)shmat(shmid, NULL, 0);
        if (psm == -1)
        {
            perror("shmat error");
            exit(1);
        }
        else
        {
            strcpy((char *)psm, argv[1]);
            printf("Send message:%s", (char *)psm);

            if ((shmdt((void *)psm)) < 0)
                perror("shmdt error");
            sleep(TIME_OUT);
        }
    }
    else
    {
        sleep(TIME_OUT);
        printf("Parent process:\n");
        printf("PID:%d\n", getpid());

        if (shmctl(shmid, IPC_STAT, &ds_buf) < 0)
        {
            perror("shmctl error\n");
            exit(1);
        }
        else
        {
            printf("Shared Memory Information:\n");
            printf("Creator PID: %d\n", ds_buf.shm_cpid);
            printf("Size: %d\n", ds_buf.shm_segsz);
            printf("Last operator PID: %d\n", ds_buf.shm_lpid);

            psm = (int)shmat(shmid, NULL, 0);

            if (psm == -1)
            {
                perror("psm error");
                exit(1);
            }
            else
            {
                printf("Received message: %s\n", (char *)psm);

                if (shmctl(shmid, IPC_RMID, NULL) < 0)
                {
                    perror("shmctl error");
                    exit(1);
                }
            }
        }
        if (shmctl(shmid, IPC_RMID, NULL) < 0)
        {
            perror("shmct error");
            exit(1);
        }
    }
    return 0;

}