#include <stdio.h>

int main(void)
{
    float number;

    printf("A float number: ");
    scanf("%f", &number);

    // 小数点记数法和指数记数法 
    printf("It's %.1f or %.1e.\n", number, number);
    printf("It's %+.3f or %.3E.\n", number, number);

    return 0;
}
