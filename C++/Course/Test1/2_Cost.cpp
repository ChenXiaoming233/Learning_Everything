#include <iostream>
using namespace std;

// 汽车
class Car
{
public:
    double L, x1;
    Car(double l, double x)
    {
        L = l;
        x1 = x;
    }
    double cost(double dist)
    {
        return dist * L * x1; // 距离 × 每公里油耗 × 油价
    }
};

// 电动汽车
class Elec
{
public:
    double M, x2;
    Elec(double m, double x)
    {
        M = m;
        x2 = x;
    }
    double cost(double dist)
    {
        return dist * M * x2; // 距离 × 每公里电耗 × 电价
    }
};

// 混动汽车
class Hy
{
public:
    double L, x1, M, x2;
    Hy(double l, double x, double m, double x2)
    {
        L = l;
        x1 = x;
        M = m;
        x2 = x2;
    }
    double cost(double dist)
    {
        double gas = dist * (L * 0.4) * x1;
        double elec = dist * (M * 0.6) * x2;
        return gas + elec;
    }
};

int main()
{
    double dist, L, x1, M, x2;
    cin >> dist >> L >> x1 >> M >> x2; // 输入：距离，每公里油耗L，汽油价格x1，每公里电耗M，电价X2

    Car c(L, x1);
    Elec e(M, x2);
    Hy h(L, x1, M, x2);

    cout << c.cost(dist) << endl;
    cout << e.cost(dist) << endl;
    cout << h.cost(dist) << endl;
    return 0;
}