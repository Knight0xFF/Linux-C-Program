//
// Created by 曾强 on 15/11/3.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/ipc.h>
#define MSGSIZE 128
struct msgbuf
{
    long mtype;
    char mtext[MSGSIZE];
};

int main(int argc, char **argv)
{
    int qid;
    key_t key;
    int ret;
    struct msgbuf buf;

    key = ftok("/Users/xiaobai/shadowsocks.json", 'a');
    if (key < 0)
    {
        perror("ftok error");
        exit(1);
    }
    qid = msgget(key, IPC_CREAT | 0666);

    if (qid < 0)
    {
        perror("megget error");
        exit(1);
    }
    while (1)
    {
        printf("Input the message:");
        fgets(buf.mtext, MSGSIZE, stdin);
        if (strncmp(buf.mtext, "exit", 4) == 0)
        {
            break;
        }
        buf.mtype = getpid();
        ret = msgsnd(qid, &buf, MSGSIZE, 0);
        if (ret < 0)
        {
            perror("msgsnd error");
            exit(1);
        }
        else
        {
            printf("Send!");
        }
    }
    return 0;
}
