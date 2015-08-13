#include <stdio.h>
#include <ctype.h>

int main()
{
    int str;
    printf("Input the characters: \n");

    for (;;)
    {
        str = getchar();
        printf("%c : %s digit\n", str, isdigit(str) ? "is":"not");
    }
    return 0;
}
