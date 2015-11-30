//
// Created by 曾强 on 15/11/30.
//

#include "lib/unp.h"

void dg_cli(FILE *fp, int sock, const SA *server_addr, socklen_t server_len)
{
    int n;
    char sendline[MAXLINE], recvline[MAXLINE+1];

    while (Fgets(sendline, MAXLINE, fp) != NULL)
    {
        Sendto(sock, sendline, strlen(sendline), 0, server_addr, server_len);

        n = Recvfrom(sock, recvline, MAXLINE, 0, NULL, NULL);

        recvline[n] = 0;
        Fputs(recvline, stdout);
    }
}

int main(int argc, char **argv)
{
    int client_sock;
    struct sockaddr_in server_addr;

    if (argc != 2)
    {
        err_quit("argc error");
    }
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERV_PORT);
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    client_sock = Socket(AF_INET, SOCK_DGRAM, 0);

    dg_cli(stdin, client_sock, (SA *)&server_addr, sizeof(server_addr));

    return 0;
}