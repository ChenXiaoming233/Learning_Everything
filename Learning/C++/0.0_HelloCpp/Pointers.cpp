#include<iostream>
#include<cstdint> // 添加此行以包含 定宽整数 的定义
#include<cstdio> // 添加此行以包含 printf 函数的定义
#include<algorithm>

double getAverange(int* arr, int num);
int* creatArray(int size);

struct ThreeInt { 
    int a;
    int b;
    int c;
};

using namespace std;
int main() {
    int a = 123;
    int* pa = &a;
    *pa = 456;
    int** ppa = &pa;
    cout << a << endl << pa << endl << ppa << endl;

    int* pb = new int(12345);  // 动态内存管理
    cout << *pb <<endl;   
    
    ThreeInt* pThreeInt = new ThreeInt {1,2,3};  // 指向结构体的指针
    cout << pThreeInt << "  " << (*pThreeInt).a << endl;
    
    int balance[5] = {1000, 2, 3, 17, 50};  // 传递指针给函数
    double avg;
    avg = getAverange(balance, 5);
    cout << avg << endl;

    int* Arr1 = creatArray(5);  // 从函数返回指针
    cout << (Arr1+1) << endl << *(Arr1+1) << endl; 

    return 0;
}

double getAverange(int* arr, int num){  // 传递指针给函数
    double avg = 0;
    double sum = 0;
    for (int i = 0; i<num ; ++i){
        sum += *(arr+i);
    }
    avg = sum / num;
    return avg;
}

int* creatArray(int size){  // 从函数返回指针
    int* arr = new int[size];
    for (int i = 0; i < size; ++i){
        *(arr+i) = i;
    }
    return arr;
}