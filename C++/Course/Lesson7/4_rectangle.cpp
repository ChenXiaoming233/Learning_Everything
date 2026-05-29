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
        return width * height; // 面积 = 宽 × 高
    }
};

int main()
{
    Rectangle rec(5, 10);                         // 5是宽度，10是高度；
    cout << "矩形的面积是：" << (int)rec << endl; // 程序输出：矩形的面积是：50
    return 0;
}