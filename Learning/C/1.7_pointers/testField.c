#include <stdio.h>

int main() {
    int a = 100;
    int* p = &a;//&是取地址运算符, &a表示的是a的内存地址; p表示的是指针变量，存储a的内存地址; &a == p == a的内存地址
    *p = *p + 100; 
    printf("%d\n", *p);
    /* *p是解引用操作符，*p == a ==a的内存地址中的值即a的值 */
    int b = 100;
    int* q= NULL;//对指针q进行初始化，规范表达
    q = &b;
    printf("%p is the address of b\n" , &b/* &b表示的是b的内存地址，此处也可以用q表示 */);
    short* j;
    j = (short*)0x1234;
    j=j+1;
    printf("%p\n",j);
    return 0;
}   
//*与&互为逆运算