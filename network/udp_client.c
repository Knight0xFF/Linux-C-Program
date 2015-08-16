#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define SERVER_PORT 10000
#define SIZE 128

int main(int argc, char **argv)
{
    int sockfd;
    struct sockaddr_in server_addr;
    unsigned int addrlen;
    char buf[SIZE];
    int cnt;
    if (argc != 3)
    {
        printf("args error\n");
        exit(1);
    }
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1)
    {
        perror("create socked fail\n");
        exit(1);
    }
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_family = AF_INET;

    bzero(&(server_addr.sin_zero), 8);
    strcpy(buf, argv[2]);
    cnt = sendto(sockfd, buf, SIZE, 0, (struct sockaddr *)&server_addr, sizeof(struct sockaddr_in));
    if (cnt == -1)
    {
        perror("send data fail\n");
        exit(1);
    }
    printf("send data: %s\n", buf);
    close(sockfd);

    return 0;
}
