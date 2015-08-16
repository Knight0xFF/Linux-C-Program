#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char **argv)
{
    struct sockaddr_in addr;
    struct hostent *host;
    if (argc != 2)
    {
        printf("arguments error.\n");
        exit(1);
    }
    inet_aton(argv[1], &addr.sin_addr);

    host = gethostbyaddr((char *)&addr.sin_addr, 4, AF_INET);

    printf("%s\n", host->h_name);

    return 0;
}
