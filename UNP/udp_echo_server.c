//
// Created by 曾强 on 15/11/30.
//

#include "lib/unp.h"

void dg_echo(int sock, SA *client_addr, socklen_t client_len)
{
    int n;
    socklen_t len;
    char message[MAXLINE];

    for ( ; ; )
    {
        len = client_len;
        n = Recvfrom(sock, message, MAXLINE, 0, client_addr, &len);

        Sendto(sock, message, n, 0, client_addr, len);
    }
}


int main(int argc, char **argv)
{
    int server_sock;
    struct sockaddr_in server_addr, client_addr;

    server_sock = Socket(AF_INET, SOCK_DGRAM, 0);

    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERV_PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    Bind(server_sock, (SA *)&server_addr, sizeof(server_addr));

    dg_echo(server_sock, (SA *)&client_addr, sizeof(client_addr));
}