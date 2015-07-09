#include <stdio.h>
#include <string.h>
#define SIZE 128

int main()
{
    char des[SIZE];
    char src[] = "Linux C";

    strcpy(des, src);
    printf("%s\n", des);
    memmove(src, src+5, strlen(src)-5);
    src[strlen(src)-11] = '\0';
    printf("%s\n", src);

    return 0;
}
