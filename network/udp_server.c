#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#define SERVER_PORT 10000
#define SIZE 100

int main()
{
    int res;
    int sockfd;
    struct sockaddr_in hostaddr;
    char buf[SIZE];
    int cnt;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1)
    {
        perror("create socked fail\n");
        exit(1);
    }
    hostaddr.sin_addr.s_addr = INADDR_ANY;
    hostaddr.sin_port = htons(SERVER_PORT);
    hostaddr.sin_family = AF_INET;
    bzero(&(hostaddr.sin_zero), 8);
    res = bind(sockfd, (struct sockaddr *)&hostaddr, sizeof(struct sockaddr));
    if (res == -1)
    {
        perror("bind socket fail\n");
        exit(1);
    }
    while (1)
    {
        cnt = recvfrom(sockfd, buf, SIZE, 0, NULL, NULL);
        if (cnt == -1)
        {
            perror("receive data fail\n");
            continue;
        }
        printf("receive data: %s \n", buf);
    }
    close(sockfd);

    return 0;
}
