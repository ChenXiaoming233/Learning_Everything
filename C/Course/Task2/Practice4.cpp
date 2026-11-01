#include <stdio.h>

int main(void)
{
    float f = 123.456f;
    char s[] = "Hello, world!";

    // 输出实数
    printf("%%f      : [%f]\n", f);      // 指定宽度 6 位小数
    printf("%%10.2f  : [%10.2f]\n", f);  // 宽 10，2 位小数，右对齐
    printf("%%-10.2f : [%-10.2f]\n", f); // 宽 10，2 位小数，左对齐

    printf("\n");

    // 输出字符串
    printf("%%s      : [%s]\n", s);      // 不指定宽度
    printf("%%-15s   : [%-15s]\n", s);   // 宽 15，左对齐
    printf("%%15s    : [%15s]\n", s);    // 宽 15，右对齐
    printf("%%15.5s  : [%15.5s]\n", s);  // 宽 15，取左 5 个字符，右对齐
    printf("%%-15.5s : [%-15.5s]\n", s); // 宽 15，取左 5 个字符，左对齐

    return 0;
}
