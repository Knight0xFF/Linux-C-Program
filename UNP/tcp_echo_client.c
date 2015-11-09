//
// Created by 曾强 on 15/11/9.
//

#include "lib/unp.h"

void
str_cli(FILE *fp, int sockfd)
{
    char	sendline[MAXLINE], recvline[MAXLINE];

    while (Fgets(sendline, MAXLINE, fp) != NULL) {

        Writen(sockfd, sendline, strlen(sendline));

        if (Readline(sockfd, recvline, MAXLINE) == 0)
            err_quit("str_cli: server terminated prematurely");

        Fputs(recvline, stdout);
    }
}


int main(int argc, char **argv)
{
    int client_sock;
    struct sockaddr_in server_addr;

    if (argc != 2)
        err_quit("args error");

    client_sock = Socket(AF_INET, SOCK_STREAM, 0);

    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERV_PORT);
    Inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    Connect(client_sock, (SA *) &server_addr, sizeof(server_addr));

    str_cli(stdin, client_sock);

    exit(0);
}
