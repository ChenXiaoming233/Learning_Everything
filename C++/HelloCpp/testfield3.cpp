#include<iostream>
#include<cstdint> // 添加此行以包含 定宽整数 的定义
#include<cstdio> // 添加此行以包含 printf 函数的定义
#include<algorithm>
#include<vector>
 
using namespace std;
 
int main() {
    std:vector<int> v(5,0);
    size_t size = v.size();
    int at1 = v.at(1);
    int* vptr = v.data();
    std::cout << &(v) << " " << vptr << " " << &v[0] << endl;
    std::cout << v.size() << " " << v.capacity();
    return 0;
}
