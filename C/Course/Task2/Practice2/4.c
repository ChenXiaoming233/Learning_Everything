#include <stdio.h>

int main(void)
{
    int a, b, c = 323;
    float x, y = 8.88f;          /* 加 f 后缀表示 float 字面量 */
    char c1 = 'a', c2;

    a = (int)y;                  /* 显式截断，明确意图 */
    x = (float)c;                /* 整数转浮点，无损失 */
    b = c1;                      /* 字符转整数，取 ASCII 码 */
    c2 = (char)c;                /* 显式截断，结果为实现定义 */

    printf("%d,%f,%d,%c\n", a, x, b, c2);

    return 0;
}
