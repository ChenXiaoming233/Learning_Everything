#include <stdio.h>

int main(void)
{
    float cups;
    printf("请输入杯数: ");
    scanf("%f", &cups);
    printf("品脱: %.2f\n", cups / 2);
    printf("盎司: %.2f\n", cups * 8);
    printf("大汤勺: %.2f\n", cups * 8 * 2);
    printf("茶勺: %.2f\n", cups * 8 * 2 * 3);
    return 0;
}
