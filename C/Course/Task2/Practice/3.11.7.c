#include <stdio.h>
int main(void)
{
    float inches;
    printf("输入身高（英寸）: ");
    scanf("%f", &inches);
    printf("身高（厘米）: %.2f\n", inches * 2.54);
    return 0;
}
