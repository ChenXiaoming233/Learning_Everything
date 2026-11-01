#include <stdio.h>

#define SQUARES 64 // 棋盘上的方格数
#define CROP 1E15  // 以粒计的美国小麦产量

int main(void)
{
    double current, total;
    int count = 1;

    printf("square grains total ");
    printf("fraction of \n");
    printf(" added grains ");
    printf("US total\n");

    total = current = 1.0; // 第一格放入一粒小麦
    printf("%4d %13.2e %12.2e %12.2e\n",
           count, current, total, total / CROP);

    while (count < SQUARES)
    {
        count = count + 1;
        current = 2.0 * current;
        total = total + current; // 更新累计数量
        printf("%4d %13.2e %12.2e %12.2e\n",
               count, current, total, total / CROP);
    }

    printf("That's all.\n");
    return 0;
}
