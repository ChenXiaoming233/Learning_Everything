#include <iostream>
#include <string>

using namespace std;

class Clock
{
private:
    int hour;
    int minute;
    int second;

public:
    // 构造函数
    Clock(int h, int m, int s)
    {
        hour = h;
        minute = m;
        second = s;
    }

    // 走秒
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

    // 打印
    void print(const string &format)
    {
        string result = format;
        int pos = 0;

        // 替换 hh
        pos = result.find("hh");
        if (pos != string::npos)
        {
            string hh = (hour < 10 ? "0" : "") + to_string(hour);
            result.replace(pos, 2, hh);
        }

        // 替换 mm
        pos = result.find("mm");
        if (pos != string::npos)
        {
            string mm = (minute < 10 ? "0" : "") + to_string(minute);
            result.replace(pos, 2, mm);
        }

        // 替换 ss
        pos = result.find("ss");
        if (pos != string::npos)
        {
            string ss = (second < 10 ? "0" : "") + to_string(second);
            result.replace(pos, 2, ss);
        }

        cout << result << endl;
    }
};

int main()
{
    Clock c(10, 12, 24);     // 初始化为10点12分24秒
    c.tick();                // 秒针走一秒
    c.print("hh点mm分ss秒"); // 打印输出：10点12分25秒
    c.print("hh-mm-ss");     // 打印输出：10-12-25
    c.print("hh:mm:ss");     // 打印输出：10:12:25
    c.print("hh:mm");        // 打印输出：10:12
    c.print("mm:ss");        // 打印输出：12:25

    return 0;
}