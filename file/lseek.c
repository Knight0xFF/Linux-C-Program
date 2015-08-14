#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <error.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#define NAME_LEN 16
#define STUDENT_NUM 32

struct student
{
    unsigned int id;
    char name[NAME_LEN];
};

int main(int argc, char **argv)
{
    int fol;
    struct student stu;
    int id;
    char name[NAME_LEN];
    if (argc != 2)
    {
        printf("args too less\n");
    }
    fol = open(argv[1], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);

    if (fol == -1)
    {
        perror("create file\n");
        exit(1);
    }

    printf("Please input student infomation:\n");
    while(1)
    {
        printf("ID:");
        scanf("%d", &id);
        if (id < 0)
        {
            printf("Input finish\n");
            exit(0);
        }
        else
        {
            printf("Name:");
            scanf("%16s", name);
            stu.id = id;
            bzero(stu.name, NAME_LEN);
            strcpy(stu.name, name);
            lseek(fol, id*sizeof(stu), SEEK_SET);

            write(fol, (char *)&stu, sizeof(stu));
        }
    }
    close(fol);

    return 0;
}

