#include <stdio.h>
int main(void)
{
    int age;
    printf("输入年龄: ");
    scanf("%d", &age);
    printf("年龄对应的秒数: %e\n", age * 3.156e7);
    return 0;
}
