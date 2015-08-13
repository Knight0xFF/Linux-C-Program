#include <stdio.h>
#include <string.h>

int main()
{
    char ch[] = "Linux C";
    char fo[] = "ux";
    char *p;

    p = strstr(ch, fo);
    if (p != NULL)
        printf("%s\n", p);
    else
        printf("Not Found!\n");

    return 0;
}
