#include <stdio.h>

int main(void)
{
    int first;
    int second;

    printf("Moduli\n");
    printf("Second operand: ");
    scanf("%d", &second);

    printf("First operand: ");
    // 第一个操作数不大于 0 时结束
    while (scanf("%d", &first) == 1 && first > 0)
    {
        printf("%d %% %d = %d\n", first, second, first % second);
        printf("Next (<=0 to quit): ");
    }
    printf("Bye\n");

    return 0;
}
