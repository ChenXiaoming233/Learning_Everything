#include <stdio.h>
#include <float.h>

int main(void)
{
    double doubleV = 1.0 / 3.0;
    float floatV = 1.0 / 3.0;

    printf("Float:\n");
    printf("%.6f\n", floatV);
    printf("%.12f\n", floatV);
    printf("%.16f\n", floatV);

    printf("double values:\n");
    printf("%.6f\n", doubleV);
    printf("%.12f\n", doubleV);
    printf("%.16f\n", doubleV);

    // 1/3 精度在 FLT_DIG 和 DBL_DIG 附近出现差异
    printf("FLT_DIG = %d\n", FLT_DIG);
    printf("DBL_DIG = %d\n", DBL_DIG);

    return 0;
}
