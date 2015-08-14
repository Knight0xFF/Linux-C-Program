#include <stdio.h>
#include <stdlib.h>
#include <error.h>
#include <unistd.h>
#define SIZE 64

int main()
{
    int res;
    char buf[SIZE];
    getcwd(buf, sizeof(buf));
    printf("%s\n", buf);
    res = chdir("/");
    if (res == -1)
    {
        perror("change dir fail\n");
        exit(1);
    }
    getcwd(buf, sizeof(buf));
    printf("%s\n", buf);

    return 0;
}
