#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t tim;
    struct tm *p;
    char *week[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    time(&tim);
    p = gmtime(&tim);
    printf("%d/%d/%d\n", (1900+p->tm_year), (1+p->tm_mon), p->tm_mday);
    printf("%s\n", week[p->tm_wday]);
    printf("%d:%d:%d\n", p->tm_hour, p->tm_min, p->tm_sec);

    return 0;
}
