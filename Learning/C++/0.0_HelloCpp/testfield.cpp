#include<iostream>
#include<cstdint> // 添加此行以包含 定宽整数 的定义
#include<cstdio> // 添加此行以包含 printf 函数的定义
#include<algorithm>
#include<ctime>

using namespace std;

int* getRandom();

int main(){
    int *arr = getRandom();
    return 0;
}


int* getRandom(){
    static int arr[10];
    srand((unsigned)time(NULL));
    for(int i = 0; i < 10; ++i){
        arr[i] = rand();
        cout << arr[i] << endl;
    }
    return arr;
}