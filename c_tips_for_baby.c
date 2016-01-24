//
// Created by 曾强 on 16/1/24.
//

#include <stdio.h>

// hello world
void hello_word()
{
    printf("Hello World!");

}

// 1.变量类型
void type_demo()
{
    printf("%s\n", "变量类型");
    // 变量声明
    int v1;

    // 变量赋值
    v1 = 0;

    // 变量声明并初始化
    float v2 = 2.333;

    // 常量
    const float Pi = 3.14159;

    // 类型
    // 1.整型
    // short int long long long char
    int v3 = 3;
    char v4 = 'z';  // 注意使用单引号才是字符

    // 2.浮点型
    // float double long double
    float v5;
    // 强制类型转换
    v5 = (float)v3;  //强制转换成float型

    // 3.数组
    int array[10] = {1, 2, 3};
    // 遍历数组
    for (v1; v1 < 10; v1++)
    {
        printf("%d ", array[v1]);
    }
    printf("\n");

    // 4.字符串
    char string1[] = "xiaobai is pig";
    char *string2 = "xiaobai not is pig";

    // 格式化输出，注意各种类型
    printf("%d, %f, %d, %c, %f, %s, %s\n", v1, v2, v3, v4, v5, string1, string2);

    printf("\n");
}

// 2.运算与表达式
void operator_demo()
{
    printf("%s\n", "运算与表达式");
    int x = 1, y = 2, z = 3;
    printf("%d, %d, %d, %d\n", x + y, x - y, x * y, x / y);
    printf("%d, %d\n", x++, ++z);  // 注意区别

    size_t size = sizeof(z);  // 获取内存大小
    printf("%zd\n", size);

    printf("\n");
}

// 3.流程控制
void flow_demo()
{
    printf("%s\n", "流程控制");
    int x = 10;

    // 关系运算
    // <, <=, >, >=, ==, !=
    // 逻辑运算
    // 与 &&, 或 ||, 非 !

    // 条件
    // if 语句
    if (x < 10)
    {
        //
    }
    else if (x < 12)
    {
        //
    }
    else
    {
        printf("ljw is pig\n");
    }

    // switch 语句
    switch (x)
    {
        case 10:
            printf("xxx\n");
            break;
        case 15:
            printf("xxx\n");
            break;
        default:
            printf("default\n");
    }

    // 循环
    // while 语句
    while (x--)
    {
        printf("xiaobai is cute\n");
        if (x == 6)
            break;
    }

    // for 语句
    for (x; x < 8; x++)
    {
        printf("xiaobai is handsome\n");
    }

    printf("\n");
}

// 4.指针
void point_demo()
{
    printf("%s\n", "指针");


    printf("\n");
}

// 5.函数
int function1(int arg1, int arg2)
{

}
// 6.结构体
// 7.内存分配
// 8.预处理

int main(int argc, char **argv)
{
    type_demo();
    operator_demo();
    flow_demo();
    point_demo();

    return 0;
}