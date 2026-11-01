#include <stdio.h>

void pound(int n);

// 修改：使用 int main(void) 并返回 0
int main(void)
{
    int times = 5;
    char ch = '!';
    float f = 6.0;

    pound(times);
    pound(ch);
    pound((int)f);

    return 0;
}

void pound(int n)
{
    while (n-- > 0)
        printf("#");
    printf("\n");
}
