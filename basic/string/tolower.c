#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char ch[] = "Linux C";
    int i;
    printf("%s\n", ch);
    for(i = 0; i < sizeof(ch); i++)
    {
        ch[i] =  tolower(ch[i]);
    }
    printf("%s\n", ch);

    return 0;
}
