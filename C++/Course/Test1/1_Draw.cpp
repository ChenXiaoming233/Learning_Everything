#include <iostream>
using namespace std;

// 点
class Point
{
public:
    int x, y;
    Point(int a, int b)
    {
        x = a;
        y = b;
    }
};

// 三角形
class Tri
{
public:
    int a, b, c;
    Tri(int x, int y, int z)
    {
        a = x;
        b = y;
        c = z;
    }
};

// 正方形
class Sqr
{
public:
    int s;
    Sqr(int x)
    {
        s = x;
    }
};

// 画板
class Canvas
{
public:
    void draw(Point &p)
    {
        cout << "正在画点，坐标是 (" << p.x << "," << p.y << ")" << endl;
    }

    void draw(Tri &t)
    {
        cout << "正在画三角形，三条边分别为 " << t.a << ", " << t.b << ", " << t.c << endl;
    }

    void draw(Sqr &s)
    {
        cout << "正在画正方形，边长为 " << s.s << endl;
    }
};

int main()
{
    Point p(1, 1);  // 创建一个点对象
    Tri t(1, 2, 3); // 创建一个三角形对象
    Canvas c;       // 创建一个画板对象
    c.draw(p);      // 画板画出点，打印输出: 正在画点，坐标是（1,1）
    c.draw(t);      // 画板画出三角形，打印输出: 正在画三角形，三条边分别为1,2,3
    return 0;
}
