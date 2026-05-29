#include <iostream>

using namespace std;

const double PI = 3.14159;

// 圆类
class Circle
{
protected:
    double r;

public:
    Circle(double r) : r(r) {}

    double area()
    {
        return PI * r * r;
    }
};

// 圆环类
class Ring : public Circle
{
private:
    double innerR;

public:
    Ring(double outerR, double innerR) : Circle(outerR), innerR(innerR) {}

    double area()
    {
        return Circle::area() - PI * innerR * innerR;
    }
};

int main()
{
    Circle c(5);
    cout << "圆面积: " << c.area() << endl;
    Ring r(10, 6);
    cout << "圆环面积: " << r.area() << endl;
    return 0;
}