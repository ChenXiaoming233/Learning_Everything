#include <stdio.h>

unsigned long Fibonacci(unsigned n) {//ATTENTION：函数不能嵌套，主函数内不能存在其它函数
    //return (n<=2 && n>0)? 1 : Fibonacci(n-1) + Fibonacci(n-2);     
    
    /*
    int m;
    if (n > 2)
        m = 1;
    else
        m = 0;
    
    switch(m){
        case 1://ATTENTION: case中只能填入整型/字符常量或常量表达式(e.g. 1+2); 不能填入变量，mnopq出现都是不合法的
            return Fibonacci(n - 1) + Fibonacci(n - 2);
            break;//ATTENTION: 在switch语句中每个case后需要加入break用以跳出循环
        default:
        //tip: default可以省略
        //bestPratice: 但为了代码的可读性，还是加上比较好
            return 1;
    }
    */

    
    if (n > 2)//ATTENTION: if后面的判断条件expression外面必须有圆括号
        return Fibonacci(n - 1) + Fibonacci(n - 2);\
        //ATTENTION: 如果有多条语句，就需要把它们放在大括号里面，组成一个复合语句。
    else
        return 1;
      
    
}

int main() {
    unsigned long n;
    scanf("%lu", &n);
    printf("%lu", Fibonacci(n));
    return 0;
};

