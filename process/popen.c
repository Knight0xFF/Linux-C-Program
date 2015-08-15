#include <stdio.h>
#include <stdlib.h>
#define SIZE 1024

int main()
{
    char buf[SIZE];
    FILE *p;
    char *cmd = "ps -f";
    if ((p = popen(cmd, "r")) == NULL)
    {
        printf("popen error\n");
        exit(1);
    }
    while (fgets(buf, sizeof(buf), p))
    {
        printf("%s", buf);
    }
    pclose(p);

    return 0;
}
