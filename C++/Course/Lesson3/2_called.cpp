#include <iostream>
using namespace std;

/**
  我在此处补充完整程序
*/

class Foo {
private:
    int id;
    static int count;
    
public:
    // 构造函数
    Foo() {
        count++;
        id = count;
        cout << "The default constructor has been called: " << id << endl;
    }
    
    // 拷贝构造函数
    Foo(const Foo& other) {
        count++;
        id = count;
        cout << "The copy constructor has been called: " << id << endl;
    }

};

int Foo::count = 0;

Foo method(Foo obj)
{
    return obj;
}

int main()
{
    Foo obj;        // 调用构造函数，输出第一行
    method(obj);    // 传值调用，先拷贝构造形参 obj，输出第二行；返回时拷贝构造临时对象，输出第三行
    return 0;
}