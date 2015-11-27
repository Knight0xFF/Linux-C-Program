//
// Created by 曾强 on 15/11/27.
//

#include "lib/unp.h"

int main(int argc, char **argv)
{
    int i, maxi, listen_sock, conn_fd, sock_fd;
    int nready;
    ssize_t n;
    char buf[MAXLINE];
    socklen_t server_len, client_len;
    struct pollfd client[OPEN_MAX];
    struct sockaddr_in client_addr, server_addr;

    listen_sock = Socket(AF_INET, SOCK_STREAM, 0);
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(SERV_PORT);

    Bind(listen_sock, (SA *)&server_addr, sizeof(server_addr));

    Listen(listen_sock, LISTENQ);
    client[0].fd = listen_sock;
    client[0].events = POLLRDNORM;
    for (i = 1; i < OPEN_MAX; i++)
        client[i].fd = -1;
    maxi = 0;

    for ( ; ; )
    {
        nready = Poll(client, maxi + 1, INFTIM);

        if (client[0].revents & POLLRDNORM)
        {
            client_len = sizeof(client_addr);
            conn_fd = Accept(listen_sock, (SA *)&client_addr, &client_len);

            for (i = 1; i < OPEN_MAX; i++)
            {
                if (client[i].fd < 0)
                {
                    client[i].fd = conn_fd;
                    break;
                }
            }
            if (i == OPEN_MAX)
                err_quit("too many clients");

            client[i].events = POLLRDNORM;
            if (i > maxi)
                maxi = i;

            if (--nready <= 0)
                continue;
        }

        for (i = 1; i <= maxi; i++)
        {
            if ( (sock_fd = client[i].fd) < 0)
                continue;

            if (client[i].revents & (POLLRDNORM | POLLERR ))
            {
                if ( (n = read(sock_fd, buf, MAXLINE)) < 0)
                {
                    if (errno == ECONNRESET)
                    {
                        close(sock_fd);
                        client[i].fd = -1;
                    }
                    else
                    {
                        err_sys("read error");
                    }
                }
                else if (n == 0)
                {
                    close(sock_fd);
                    client[i].fd = -1;
                }
                else
                    write(sock_fd, buf, n);

                if (--nready <= 0)
                    break;
            }
        }
    }
}
