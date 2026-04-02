#include <iostream>
using namespace std;

class Re
{
public:
    double x1, y1, x2, y2;
    void set(double a, double b, double c, double d)
    {
        x1 = a;
        y1 = b;
        x2 = c;
        y2 = d;
    }
};

void judge(Re r1, Re r2)
{
    if (r1.x2 < r2.x1 or r2.x2 < r1.x1 or r1.y2 < r2.y1 or r2.y2 < r1.y1)
        cout << "相离";

    else if ((r1.x1 <= r2.x1 && r1.x2 >= r2.x2 && r1.y1 <= r2.y1 && r1.y2 >= r2.y2)     // r1 包含 r2
             or (r2.x1 <= r1.x1 && r2.x2 >= r1.x2 && r2.y1 <= r1.y1 && r2.y2 >= r1.y2)) // 或 r2 包含 r1
        cout << "包含";
    else
        cout << "相交";
}

int main()
{
    Re r1, r2;
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    r1.set(x1, y1, x2, y2);
    cin >> x1 >> y1 >> x2 >> y2;
    r2.set(x1, y1, x2, y2);
    judge(r1, r2);
    return 0;
}