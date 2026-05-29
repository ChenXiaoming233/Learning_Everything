#include <iostream>
using namespace std;

// public
class Bad
{
public:
    int age; // 任何地方都能直接访问和修改

    Bad(int a) : age(a) {}
};

// private
class Good
{
private:
    int age; // 外部无法直接访问

public:
    Good(int a) : age(a) {}

    // 通过 public 成员函数来访问和修改数据
    int getAge() const
    {
        return age;
    }

    void setAge(int a)
    {
        if (a >= 0 && a <= 150)
        {
            age = a;
        }
        else
        {
            cout << "年龄输入错误！年龄应在0-150之间" << endl;
        }
    }
};

int main()
{
    // public 的坏处：
    Bad bad(20);
    cout << "Bad 年龄：" << bad.age << endl;
    bad.age = -5; // 可以直接修改为非法值
    cout << "修改后年龄：" << bad.age << endl;

    // private 的好处
    Good good(20);
    cout << "Good 年龄：" << good.getAge() << endl;
    good.setAge(-5); // 尝试设置非法值，会被拦截，可以验证数据的有效性
    cout << "尝试设置-5后的年龄：" << good.getAge() << endl;

    return 0;
}
