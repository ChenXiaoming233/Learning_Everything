#include <iostream>
using namespace std;

/* 我在此处补充代码 */
class Foo
{
private:
    static int count;

public:
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

    static int getNum()
    {
        return count;
    }

    // 对象销毁时活动对象数减1
    ~Foo()
    {
        count--;
    }
};
int Foo::count = 0;

void func(Foo obj)
{
}

int main()
{
    Foo obj1;
    Foo obj2;
    cout << "当前对象数：" << Foo::getNum() << endl;
    func(obj1);
    cout << "当前对象数：" << Foo::getNum() << endl;
    return 0;
}