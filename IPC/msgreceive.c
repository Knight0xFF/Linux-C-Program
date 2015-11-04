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

int main()
{
    int qid;
    int ret;
    key_t key;
    struct msgbuf buf;

    key = ftok("/Users/xiaobai/shadowsocks.json", 'a');
    if (key < 0)
    {
        perror("ftok error");
        exit(1);
    }

    qid = msgget(key, IPC_EXCL | 0666);
    if (qid < 0)
    {
        perror("msgget error");
        exit(1);
    }

    while (1)
    {
        memset(&buf, 0, sizeof(buf));
        ret = msgrcv(qid, &buf, MSGSIZE, 0, 0);
        if (ret < 0)
        {
            perror("msgrcv error");
            exit(1);
        }
        else
        {
            printf("Recevived message: \n");
            printf("Type=%d, Length=%d, Text=%s\n", buf.mtype, ret, buf.mtext);
        }
    }

    return 0;
}