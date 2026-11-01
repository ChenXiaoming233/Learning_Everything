#include <stdio.h>

int main(void)
{
    char ch;
    int i;
    float fl;

    fl = i = ch = 'C';
    printf("ch = %c, i = %d, fl = %2.2f\n", ch, i, fl);

    ch = ch + 1;
    i = fl + 2 * ch;
    fl = 2.0 * ch + i;
    printf("ch = %c, i = %d, fl = %2.2f\n", ch, i, fl);

    // 修改：先取整数低 8 位再转 char
    ch = (char)((long)5212205.17 & 0xFFL);
    printf("Now ch = %c\n", ch);

    return 0;
}
