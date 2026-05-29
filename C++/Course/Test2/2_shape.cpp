#include <iostream>
using namespace std;

// 抽象类
class shape
{
public:
    // 纯虚函数
    virtual float area() = 0;

    // 虚析构函数
    virtual ~shape() {}
};

// 圆形类
class Circle : public shape
{
private:
    float r;

public:
    Circle(float r) : r(r) {}
    virtual float area()
    {
        return 3.14 * r * r;
    }
};

// 矩形类
class Rectangle : public shape
{
private:
    float l;
    float w;

public:
    Rectangle(float l, float w) : l(l), w(w) {}
    virtual float area()
    {
        return l * w;
    }
};

float total(shape *s[], int n) // n 表示数组 s 的长度，即图形个数
{
    float sum = 0.0;
    for (int i = 0; i < n; i++)
        sum += s[i]->area();
    return sum;
}

int main()
{
    Circle c1(5.0);
    Circle c2(3.0);
    Rectangle r1(4.0, 6.0);

    // 指针数组存放图形地址
    shape *shapes[3];
    shapes[0] = &c1;
    shapes[1] = &c2;
    shapes[2] = &r1;

    float totalArea = total(shapes, 3);

    cout << "圆1面积：" << c1.area() << endl;
    cout << "圆2面积：" << c2.area() << endl;
    cout << "矩形面积：" << r1.area() << endl;
    cout << "总面积：" << totalArea << endl;

    return 0;
}