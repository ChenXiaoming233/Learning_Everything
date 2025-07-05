//好像需要学会数组才能实现所以烂尾了
#include <stdio.h>
double averange(int number, ...);

int main() {
    int number;
    scanf("需要求平均数的数的数%d",number);
    
    printf("%d\n",averange(number,1));
}

//这个文件展示了函数进行的一些功能，此时的函数相当于超链接，用于调用一个功能

double averange(int number, ...){
    double total = 0;
    va_list Averange;
    va_start(Averange,number);
    for(int j = 0; j <= number; number++) {
        total += va_arg (Averange, number=1);
    }
    var_end(Averange);
    return total/number;
}