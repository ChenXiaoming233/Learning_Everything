#include<iostream>
#include<cstdint> // 添加此行以包含 定宽整数 的定义
#include<cstdio> // 添加此行以包含 printf 函数的定义
#include<algorithm>

using namespace std;
struct ThreeInt{
    int a;
    int b;
    int c;
};

int main() {
    ThreeInt* p1 = new ThreeInt{1,2,3};
    int size = 5;
    int* p2 = new int[size];
    *(p2+1) = 4;
    cout << p2[1] << endl;

    int* p3 = new int(3);
    cout << *p3 << endl;
    
    int height,width;
    cin >> height >> width;  //输入4,5
    int** a = new int*[height];
    for (int i = 0; i<height; ++i ){
        a[i] = new int[width];
    }
    a[3][4] = 3;
    cout << a[3][4] << endl;
    for (int i = 0; i<height; ++i ){
        delete[] a[i];
    }
    delete[] a;

    int N,M;
    cin >> N >> M;
    int arr[N*M];
    int k = 0, S = 0;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            arr[i*M+j] = k;
            k++;
            S = S + arr[i*M+j];
        }
    }
    cout << S << endl;



    return 0;

}