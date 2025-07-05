#include<iostream>
#include<cstdint> // 添加此行以包含 定宽整数 的定义
#include<cstdio> // 添加此行以包含 printf 函数的定义
#include<algorithm>

using namespace std;
int main() {
    double a = 321.2;
    cout <<"I am a C艹 programmer.测试"<<"  "<<a<<endl;
    printf("%4.2f\n",a);
    printf("%d\n",INT_FAST32_MAX);
    long long b;
    int64_t c;
    cin >> b >> c;
    cout << max(b,c) << endl;
    int32_t d,e,i= 1;
    d = i++;
    e = ++i;
    cout << d << endl;
    cout << e << endl;
    return 0;
}