//
// Created by 曾强 on 15/11/3.
//

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#define BUFSIZE 256

int main(int argc, char **argv)
{
    int fd;
    char buf[BUFSIZE];
    if (argc != 2)
    {
        printf("args error\n");
        exit(1);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        perror("open pipe error");
        exit(1);
    }

    printf("Client: \n");
    read(fd, buf, sizeof(buf));
    printf("received message: %s\n", buf);

    return 0;
}