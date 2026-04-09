#include <iostream>

class Circle
{
private:
    double rad;

public:
    Circle(double r) : rad(r) {}

    double getS() const // 获取面积
    {
        return 3.14 * rad * rad;
    }

    double getR() const // 获取半径
    {
        return rad;
    }
};

// 圆柱体类
class Cy
{
private:
    Circle base;   // 底面圆对象
    double height; // 高

public:
    // 初始化底面圆和高
    Cy(double r, double h) : base(r), height(h) {}

    // 计算体积
    double getV() const
    {
        return base.getS() * height;
    }
};
