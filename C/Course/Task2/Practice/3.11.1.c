#include <stdio.h>
#include <float.h>

int main(void)
{
    int i = 2147483647;
    printf("整数上溢: %d + 1 = %d\n", i, i + 1);

    float f = FLT_MAX;
    printf("浮点数上溢: %e * 10 = %e\n", f, f * 10.0f);

    float g = FLT_MIN;
    printf("浮点数下溢: %e / 1e10 = %e\n", g, g / 1e10f);

    return 0;
}

