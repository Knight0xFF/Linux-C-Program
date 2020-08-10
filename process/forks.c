#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void child_process1()
{
    printf("child1 pid is: %d \n", getpid());
}

void child_process2()
{
    printf("child2 pid is: %d \n", getpid());
}

int main()
{
    int a = 0;
    if (a > 0)
    {
        printf("a > 0");
    }
    else if (a < 0)
    {
        printf("a < 0");
    }

    return 0;
}
