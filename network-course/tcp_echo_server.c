#include <netdb.h>
#include <sys/socket.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include<stdlib.h>
#include<string.h>

#define EHCO_PORT    8080
#define MAX_CLIENT_NUM        10

void overflow(char *recv_buff)
{
    char buffer[10];
    strcpy(buffer, recv_buff);
}


int main()
{
    //建立一个 socket  
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);

    if(socketfd == -1)
    {
        printf("errno=%d ", errno);
        exit(1);
    }
    else
    {
        printf("socket create successfully ");
    }
    //定义一个ip网络地址scokaddr_in 结构体变量sa
    struct sockaddr_in sa;

    //创建sockaddr_in 变量之后，调用bzero()以确保该变量中的所有成员都为0是一个好习惯
    //还有一种方法memset(&sa,0,sizeof(sa));
    bzero(&sa, sizeof(sa));

    //设置地址族
    sa.sin_family = AF_INET;
    //htons()函数将short类型的值从主机字节序转换为网络字节序ps：其实就是端口，short类型，0-65535
    sa.sin_port = htons(EHCO_PORT);

    //long类型的ip地址 4个字节 INADDR_ANY 代表任意地址 系统默认0.0.0.0
    //0.0.0.0表示来自任意网卡的包都要发给server。
    sa.sin_addr.s_addr = htons(INADDR_ANY);

    //将创建的套接字绑定到一个本地ip地址和端口号以用于TCP通信
    if(bind(socketfd, (struct sockaddr *)&sa, sizeof(sa))!= 0)
    {
        printf("bind failed ");
        printf("errno=%d ", errno);
        exit(1);
    }
    else
    {
        printf("bind successfully ");
    }

    //程序调用listen() 开始监听客户端的连接  然后调用accept来真正的接收客户端的连接
    if(listen(socketfd ,MAX_CLIENT_NUM) != 0)
    {
        printf("listen error ");
        exit(1);
    }
    else
    {
        printf("listen successfully ");
    }


    int clientfd;
    struct sockaddr_in remote_addr;
    char buff[101];
    int len =  sizeof(remote_addr);
    while((clientfd = accept(socketfd, (struct sockaddr *)&remote_addr, &len)) > 0 )
    {
        int n;
        while((n = recv(clientfd,buff, 100,0 )) > 0)
        {
            overflow(buff);
            printf("number of receive bytes = %d ", n);

            buff[n] = '\0';
            printf("%s\n", buff);

            if(send(clientfd, buff, n, 0) < 0)
            {
                perror("write");
                return 1;
            }

            if(strcmp(buff, "quit") == 0)
            {
                printf("server is closed");
                break;
            }
        }

        close(clientfd);
    }

    close(socketfd);

    return 0;
}


