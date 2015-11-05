#include "unp.h"

#define SERVER_PORT 10000
#define SIZE 128

int main(int argc, char **argv)
{
    int res;
    int sockfd;
    int cnt;
    struct sockaddr_in server_addr;
    char buf[SIZE];
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd  == -1)
    {
        perror("create socked fail\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    bzero(&(server_addr.sin_zero), 8);
    res = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr));
    if (res == -1)
    {
        perror("connect fail\n");
        exit(1);
    }
    strcpy(buf, argv[1]);
    cnt = send(sockfd, buf, SIZE, 0);
    if (cnt == -1)
    {
        perror("send data fail\n");
        exit(1);
    }
    printf("send data: %s \n", buf);
    close(sockfd);

    return 0;

}
