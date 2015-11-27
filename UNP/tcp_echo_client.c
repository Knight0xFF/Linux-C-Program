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


void str_cli_select(FILE *fp, int sockfd)
{
    int max_fd1, stdin_eof;
    fd_set rset;
    char buf[MAXLINE];
    int n;

    stdin_eof = 0;
    FD_ZERO(&rset);

    for (;;)
    {
        if (stdin_eof == 0)
            FD_SET(fileno(fp), &rset);
        FD_SET(sockfd, &rset);
        max_fd1 = max(fileno(fp), sockfd) + 1;
        select(max_fd1, &rset, NULL, NULL, NULL);

        if (FD_ISSET(sockfd, &rset))
        {
            if ( (n = read(sockfd, buf, MAXLINE)) == 0)
            {
                if (stdin_eof == 1)
                    return;
                else
                    err_quit("server terminated prematurely");
            }
            Writen(fileno(stdout), buf, n);
        }

        if (FD_ISSET(fileno(fp), &rset))
        {
            if ( (n = read(fileno(fp), buf, MAXLINE)) == 0)
            {
                stdin_eof = 1;
                shutdown(sockfd, SHUT_WR);
                FD_CLR(fileno(fp), &rset);
                continue;
            }
            Writen(sockfd, buf, MAXLINE);
        }
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
