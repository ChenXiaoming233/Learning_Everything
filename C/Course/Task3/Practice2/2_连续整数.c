#include <stdio.h>

int main(void)
{
    int number;
    int limit;

    printf("Integer: ");
    scanf("%d", &number);

    // 包含起点在内，共输出 11 个整数
    limit = number + 10;
    printf("Result: ");
    while (number <= limit)
    {
        printf("%d ", number);
        number++;
    }
    printf("\n");

    return 0;
}
