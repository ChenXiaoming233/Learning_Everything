#include <iostream>

using namespace std;

// 基类A
class A
{
protected:
    int a;

public:
    A(int x)
    {
        a = x;
    }
};

// 派生类A1
class A1 : public A
{
protected:
    int b;

public:
    A1(int x, int y) : A(y)
    {
        b = x;
    }
};

// 派生类A2
class A2 : public A1
{
private:
    int c;

public:
    A2(int x, int y, int z) : A1(y, z)
    {
        c = x;
    }

    void show()
    {
        cout << "c = " << c << endl;
        cout << "b = " << b << endl;
        cout << "a = " << a << endl;
    }
};

int main()
{
    A2 obj(10, 20, 30); // c=10, b=20, a=30
    obj.show();
    return 0;
}