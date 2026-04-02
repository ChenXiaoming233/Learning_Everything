#include <iostream>
using namespace std;

/* 我在此处补充代码 */
class Foo
{
private:
    static int count;         // 当前活动对象个数
    static const int MAX = 3; // 最大对象数

    // 禁止外部的创建行为
    Foo()
    {
        count++;
        cout << "创建第" << count << "个对象" << endl;
    }
    Foo(const Foo &other)
    {
        count++;
        cout << "创建第" << count << "个对象" << endl;
    }

public:
    static int getNum()
    {
        return count;
    }

    // 通过 create() 创建对象
    static Foo *create()
    {
        if (count < MAX)
            return new Foo();
        else
        {
            cout << "对象数量已达上限" << endl;
            return nullptr;
        }
    }

    // 对象销毁时活动对象数减1
    ~Foo()
    {
        count--;
    }
};
int Foo::count = 0;

void func(Foo *obj)
{
}

int main()
{
    // 构造函数私有
    // Foo obj1;
    // Foo obj2;

    // 通过 create() 来创建对象
    Foo *obj1 = Foo::create();
    Foo *obj2 = Foo::create();
    Foo *obj3 = Foo::create();
    // Foo *obj4 = Foo::create(); // 对象数量已达上限

    cout << "当前对象数：" << Foo::getNum() << endl;
    func(obj1);
    cout << "当前对象数：" << Foo::getNum() << endl;
    return 0;
}