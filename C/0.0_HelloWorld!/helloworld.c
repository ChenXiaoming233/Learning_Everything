#include <stdio.h>//预处理指令，引入标准输入输出函数库
#include "max.h"//预处理指令，引入自定义的函数库
/* 我的第不知道多少个 C 程序 *///这是注释
int main()//主函数，程序从这里执行
{
    int a = 10;
    int b = 20;
    int c = Max(a,b);
    printf("%d\n",c);
    printf("HelloWorld!");
    return 0;//程序结束，返回 0 值
}