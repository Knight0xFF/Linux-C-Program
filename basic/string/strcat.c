#include <stdio.h>
#include <string.h>
#define SIZE 64

int main()
{
    char ch1[SIZE] = "Linux C";
    char ch2[SIZE] = " is good~~";
    strncat(ch1, ch2, strlen(ch2));
    printf("%s\n", ch1);
    printf("%s\n", ch2);

    return 0;
}
