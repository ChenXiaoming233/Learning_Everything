#include <stdio.h>
#include <stdlib.h>
void numberExchange(int* a, int* b);
void (*numberExchange_ptf)(int*,int*) = &numberExchange;
void myPrintf(int a, int b);
void (*myPrintf_ptf)(int,int) = &myPrintf;
void worngPrint(void);
int favoriteNumber(int a);

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    (*numberExchange)(&a, &b);//利用&，传入的是函数的*内存地址*
    (*myPrintf_ptf)(a, b);
    printf("anyway I prefer to print a nubmer %d here\n", favoriteNumber(a));
    return 0;
}

//这个文件展示了函数进行的一些功能，此时的函数相当于超链接，用于调用一个功能

//利用指针，通过内存地址操作函数外的变量
int favoriteNumber(int a){
    return a;
}

void numberExchange(int* a,int* b){//向函数传入两个*指针*变量
    int temp = *a;
    *a = *b;
    *b = temp;
}

void wrongPrint(void){
    printf("Something went wrong!(fake\n");
}

void myPrintf(int a, int b){
    printf("%d %d\n", a, b);
    atexit(wrongPrint);
}
