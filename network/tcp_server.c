#include "unp.h"

#define SERVER_PORT 10000
#define LENGTH 10
#define SIZE 128

int main()
{
    int res;
    int sockfd;
    int clientfd;
    struct sockaddr_in hostaddr;
    struct sockaddr_in clientaddr;
    unsigned int addrlen;
    char buf[SIZE];
    int cnt;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        perror("create socket fail\n");
        exit(1);
    }
    hostaddr.sin_family = AF_INET;
    hostaddr.sin_port = htons(SERVER_PORT);
    hostaddr.sin_addr.s_addr = INADDR_ANY;
    res = bind(sockfd, (struct sockaddr *)&hostaddr, sizeof(struct sockaddr));
    if (res == -1)
    {
        perror("bind socked fail\n");
        exit(1);
    }
    res = listen(sockfd, LENGTH);
    if (res == -1)
    {
        perror("set listen mode fail\n");
        exit(1);
    }


    printf("Wating for client connection...\n");
    while (1)
    {
        addrlen = sizeof(struct sockaddr_in);
        clientfd = accept(sockfd, (struct sockaddr *)&clientaddr, &addrlen);
        if (clientfd == -1)
        {
            perror("receive connection request error\n");
            continue;
        }
        printf("client IP: %s\n", inet_ntoa(clientaddr.sin_addr));

        cnt = recv(clientfd, buf, SIZE, 0);
        if (cnt == -1)
        {
            perror("receive data error\n");
            exit(1);
        }
        printf("receive data: %s\n", buf);
        close(clientfd);
    }

    return 0;
}
