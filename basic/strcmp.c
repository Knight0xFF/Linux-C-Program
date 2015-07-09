#include <stdio.h>
#include <string.h>

int main()
{
    char ch1[] = "Linux C";
    char ch2[] = "Linux C";
    int res;

    printf("ch1 : %s\n", ch1);
    printf("ch2 : %s\n", ch2);

    res = strcmp(ch1, ch2);
    if (res == 0)
        printf("ch1 == ch2\n");
    else if (res < 0)
        printf("ch1 < ch2\n");
    else
        printf("ch1 > ch2\n");

    return 0;
}
