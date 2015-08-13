#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch1[] = "1111";
    char ch2[] = "2222";
    char ch3[] = "ABCD";

    printf("ch1 = %ld\n", strtol(ch1, NULL, 2));
    printf("ch2 = %ld\n", strtol(ch2, NULL, 10));
    printf("ch3 = %ld\n", strtol(ch3, NULL, 16));
}
