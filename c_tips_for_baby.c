//
// Created by XiaoBai on 16/1/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    // 指针变量保存内存地址，内存地址保存变量的值
    // 指针定义：类型 *变量名
    int *ptr1;  // 值是某个整型变量的地址
    long *xiaobai;  // xiaobai 是个没有对象的野指针

    int value1 = 3;
    // 赋值
    ptr1 = &value1;

    // 数组指针
    int array[5] = {0, 1, 2, 3,4}, *ptr2;
    ptr2 = array;
    ptr2 = &array[0];   // 两者等价

    // & 取址运算符 *取值运算符
    printf("%p, %p, %d\n", ptr1, &ptr1, *ptr1);
    for (value1 = 0; value1 < 5; value1++)
    {
        printf("数组输出:%d, 指针输出:%d", array[value1], *ptr2++);
        printf("\n");
    }

    printf("\n");
}

// 5.函数
int function1(int arg1, int arg2)
{
    // 返回arg1，arg2的较大者
    return (arg1 > arg2) ? arg1 : arg2;
}

void function2(int *arg1, int *arg2)
{
    // 交换两个变量的值，使用指针实现
    int temp;
    temp = *arg1;
    *arg1 = *arg2;
    *arg2 = temp;
}

int function3(int n)
{
    // 斐波那契数列，递归的使用
    if (n <= 2)
        return n;
    else
        return function3(n - 1) + function3(n - 2);
}

void function_demo()
{
    printf("%s\n", "函数");
    int a = 10, b = 20, result;
    // 函数调用与返回
    result = function1(a, b);
    printf("%d\n", result);

    //参数为地址
    function2(&a, &b);
    printf("a = %d, b = %d\n", a, b);

    for (a = 0; a < b; a++)
        printf("%d ", function3(a));

    printf("\n");
}


// 6.结构体
/* 定义方法：
 * struct 结构名{
 *      成员列表
 * }
 *
*/
struct Pig {
    char head;
    int fat;
};

struct Fool {
    struct Pig xiaobai;  // 使用Pig结构
    int number;
} *fool_ptr, fool = {'z', 3, 5}; // 顺便定义了两个Fool类型的变量和指针变量

void struct_demo()
{
    printf("%s\n", "结构体");
    fool_ptr = &fool;
    fool_ptr->number = 666;

    printf("%c, %d, %d\n", fool_ptr->xiaobai.head, fool_ptr->xiaobai.fat, fool_ptr->number);

    printf("\n");
}


// 7.内存分配
void memory_demo()
{
    printf("%s\n", "内存分配");
    char *xiaobai;  //

    xiaobai = (char *)malloc(66 * sizeof(char));
    if (xiaobai == NULL)
        exit(1);
    strncpy(xiaobai, "给你个对象吧", 20);
    printf("%s\n", xiaobai);

    free(xiaobai);  // 还是没对象吧
    xiaobai = NULL;

    printf("\n");
}

// 8.预处理
// include 包含头文件
#define MAXNUMBER 250;

int main(int argc, char **argv)
{
    hello_word();
    //type_demo();
    //operator_demo();
    //flow_demo();
    //point_demo();
    //function_demo();
    //struct_demo();
    //memory_demo();

    return 0;
}