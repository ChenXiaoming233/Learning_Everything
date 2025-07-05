#include<iostream>
#include<cstdint> // 添加此行以包含 定宽整数 的定义
#include<cstdio> // 添加此行以包含 printf 函数的定义
#include<algorithm>
 
using namespace std;
 
class Box {
public:
    double length;
    // setLength 函数接受一个 Box 对象作为参数
    void setLength(Box &otherBox) {  // 使用引用来传递对象
        length = otherBox.length;
    }
};

int main() {
    Box box1, box2;
    box2.length = 15;  // 设置 box2 的 length 为 15
    // box1.setLength(box2) 让 box1 的 length 等于 box2 的 length
    box1.setLength(box2);  // 传入 box2 对象
    cout << box2.length;
}
