#include <stdio.h>
int main(void)
{
    float quarts;
    printf("输入水的夸脱数: ");
    scanf("%f", &quarts);
    printf("水分子的数量: %e\n", quarts * 950.0 / 3.0e-23);
    return 0;
}
