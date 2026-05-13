#include <iostream>
using namespace std;

// A型 不能超载
class CarA
{
public:
    int lim; // 额定人数
    int on;  // 车上当前人数
    int tot; // 累计搭载人数

    CarA(int l)
    {
        lim = l;
        on = 0;
        tot = 0;
    }

    void station(int p)
    {
        if (p > 0)
        {
            int canTake;
            if (on + p <= lim)
            {
                canTake = p; // 都能上
            }
            else
            {
                canTake = lim - on; // 只能上这么多
            }
            on += canTake;
            tot += canTake;
        }
        else
        { // 下车
            int down = -p;
            if (down > on)
                down = on;
            on -= down;
        }
    }

    void print()
    {
        cout << tot << " " << on << endl;
    }
};

// B型：可以超载
class CarB
{
public:
    int lim;
    int on;
    int tot;

    CarB(int l)
    {
        lim = l;
        on = 0;
        tot = 0;
    }

    void station(int p)
    {
        if (p > 0)
        { // 上车
            int maxCan = lim * 2;
            int canTake;
            if (on + p <= maxCan)
                canTake = p;
            else
                canTake = maxCan - on;
            on += canTake;
            tot += canTake;
        }
        else
        { // 下车
            int down = -p;
            if (down > on)
                down = on;
            on -= down;
        }
    }

    void print()
    {
        cout << tot << " " << on << endl;
    }
};

int main()
{
    int limA, limB;
    cout << "请输入两种车的额定人数：" << endl;
    cin >> limA >> limB;

    CarA a(limA);
    CarB b(limB);

    cout << "请输入站数：" << endl;
    int n, num;
    cin >> n;

    cout << "请输入每站的上下客人数：" << endl;
    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        a.station(p);
        b.station(p);
    }

    cout << "结果：" << endl;
    a.print();
    b.print();

    return 0;
}