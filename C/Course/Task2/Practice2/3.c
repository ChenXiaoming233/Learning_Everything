#include <stdio.h>
#include <math.h>

int main(void)
{
    float f;
    f = 123.456f;                 /* 用 f 后缀明确表示 float 字面量 */

    if (fabs((double)f - 123.456) < 1e-6)   /* 用容差比较 */
        printf("f is equal to 123.456 indeed.\n");
    else
        printf("In fact, f is equal to %f\n", f);

    return 0;
}
