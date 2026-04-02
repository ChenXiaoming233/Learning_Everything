#include <iostream>
using namespace std;

class Clock
{
private:
    int hour;
    int minute;
    int second;

public:
    void set(int h, int m, int s)
    {
        hour = h;
        minute = m;
        second = s;
    }
    void tick()
    {
        second++;
        if (second >= 60)
        {
            second = 0;
            minute++;
            if (minute >= 60)
            {
                minute = 0;
                hour++;
                if (hour >= 24)
                    hour = 0;
            }
        }
    }
    void show()
    {
        cout << hour << ":" << minute << ":" << second << endl;
    }
};

int main()
{
    Clock clo1;
    cout << "CLOCK A:" << endl;
    clo1.set(2, 30, 0); // 设置时钟的当前时间
    for (int i = 0; i < 10; i++)
    {
        clo1.tick(); // 时钟增加1秒
        clo1.show(); // 第一次循环打印输出：2:30:1
    }
    return 0;
}