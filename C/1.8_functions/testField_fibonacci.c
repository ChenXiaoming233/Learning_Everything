#include <stdio.h>

//这个文件展示了函数进行的一些运算
unsigned long long Fibonacci(unsigned long long n) {//ATTENTION：函数不能嵌套，主函数内不能存在其它函数
    return (n<=2 && n>0)? 1 : Fibonacci(n-1) + Fibonacci(n-2);
    //ATTENTION:return应放置在三元运算符的前方
}

int main() {
    unsigned long n;//ATTENTION: 不要无脑就是 int
    scanf("%lu", &n);//ATTENTION: 不要无脑就是 %d, printf 与 scanf 函数的输入参数类型应与函数参数类型一致
    printf("%lu", Fibonacci(n));
    return 0;
};

