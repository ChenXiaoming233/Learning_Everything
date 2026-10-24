#include <stdio.h>

int main() {
    char a = -5;                 // 有符号8位整数
    unsigned char b = a;         // 强制赋值给无符号8位整数
    
    printf("【变量a】十进制显示: %d | 十六进制显示: 0x%X\n", a, a);
    printf("【变量b】十进制显示: %u | 十六进制显示: 0x%X\n", b, b);
    
    return 0;
}
