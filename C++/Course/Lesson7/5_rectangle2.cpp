#include <iostream>

using namespace std;

class Rectangle
{
private:
    int width;
    int height;

public:
    Rectangle(int w, int h)
    {
        width = w;
        height = h;
    }

    // 重载 int()，返回面积
    operator int()
    {
        return width * height;
    }

    // 重载 a++, 自增再返回新值
    Rectangle &operator++()
    {
        width++;
        height++;
        return *this;
    }

    // 重载 ++a, 返回旧值再自增
    Rectangle operator++(int)
    {
        Rectangle temp = *this;
        width++;
        height++;
        return temp;
    }
};

int main()
{
    Rectangle rec(5, 10);
    int area = rec;                             
    cout << "矩形的面积是：" << (int)rec << endl; // 程序输出：矩形的面积是：50
    cout << "矩形新的面积是：" << (int)++rec++ << endl; // 程序输出：矩形新的面积是：66
    cout << "矩形新的面积是：" << (int)rec << endl; // 程序输出：矩形新的面积是：66
    cin.get();
    return 0;
}