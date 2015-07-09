#include <stdio.h>
#include <string.h>

int main()
{
    char ch[] = "Linux C is my want";
    printf("%s\n", ch);
    memset(ch, 'z', 5);
    printf("%s\n", ch);
    bzero(ch, 5);
    printf("%s\n", ch);

    return 0;
}
