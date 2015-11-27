//
// Created by 曾强 on 15/11/27.
//

#include "lib/unp.h"

int main(int arc, char **argv)
{
    int i, maxi, max_fd, listen_sock, conn_fd, sock_fd;
    int nready, client[FD_SETSIZE];

    ssize_t n;
    fd_set rset, allset;
    char buf[MAXLINE];
    socklen_t client_len;
    struct sockaddr_in server_addr, client_addr;

    listen_sock = Socket(AF_INET, SOCK_STREAM, 0);

    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERV_PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    Bind(listen_sock, (SA *)&server_addr, sizeof((server_addr)));
    Listen(listen_sock, LISTENQ);
    max_fd = listen_sock;
    maxi = -1;

    for (i = 0; i < FD_SETSIZE; i++)
    {
        client[i] = -1;
    }

    FD_ZERO(&allset);
    FD_SET(listen_sock, &allset);

    for ( ; ; )
    {
        rset = allset;
        nready = Select(max_fd+1, &rset, NULL, NULL, NULL);

        if (FD_ISSET(listen_sock, &rset))
        {
            client_len = sizeof(client_addr);
            conn_fd = Accept(listen_sock, (SA *)&client_addr, &client_len);

            for (i = 0; i < FD_SETSIZE; i++)
            {
                if (client[i] < 0)
                {
                    client[i] = conn_fd;
                    break;
                }
            }

            if (i == FD_SETSIZE)
            {
                err_quit("too many clients");
            }

            FD_SET(conn_fd, &allset);
            if (conn_fd > max_fd)
                max_fd = conn_fd;
            if (i > maxi)
                maxi = i;
            if (--nready <= 0)
                continue;
        }

        for (i = 0; i <= maxi; i++)
        {
            if ( (sock_fd = client[i]) < 0)
                continue;
            if (FD_ISSET(sock_fd, &rset))
            {
                if ( (n = read(sock_fd, buf, MAXLINE)) == 0)
                {
                    close(sock_fd);
                    FD_CLR(sock_fd, &allset);
                    client[i] = -1;
                }
                else
                    write(sock_fd, buf, n);

                if (--nready <= 0)
                    break;
            }
        }
    }

}
