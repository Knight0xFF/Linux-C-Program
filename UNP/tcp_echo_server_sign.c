//
// Created by 曾强 on 15/11/9.
//

#include "lib/unp.h"

void str_echo(int sockfd)
{
    ssize_t		n;
    char		buf[MAXLINE];

    again:
    while ( (n = read(sockfd, buf, MAXLINE)) > 0)
        Writen(sockfd, buf, n);

    if (n < 0 && errno == EINTR)
        goto again;
    else if (n < 0)
        err_sys("str_echo: read error");
}

void sig_child(int signo)
{
    pid_t pid;
    int stat;

    pid = wait(&stat);
    printf("child %d terminated\n", pid);
    return;
}


int main(int argc, char **argv)
{
    int listen_sock, conn_fd;
    pid_t child_pid;
    socklen_t client_len;
    struct sockaddr_in client_addr, server_addr;

    listen_sock = Socket(AF_INET, SOCK_STREAM, 0);

    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(SERV_PORT);

    Bind(listen_sock, (SA *)&server_addr, sizeof(server_addr));

    Listen(listen_sock, LISTENQ);
    Signal(SIGCHLD, sig_child);

    for (;;)
    {
        client_len = sizeof(client_addr);
        conn_fd = Accept(listen_sock, (SA *)&client_addr, &client_len);
        if ( (child_pid = fork()) == 0)
        {
            close(listen_sock);
            str_echo(conn_fd);
            close(conn_fd);
            exit(0);
        }
        close(conn_fd);
    }

}