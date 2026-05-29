#include <iostream>
#include <iomanip>

using namespace std;

// 时间类
class Time
{
protected:
    int h, m, s;

public:
    Time(int h, int m, int s) : h(h), m(m), s(s) {}

    void print()
    {
        cout << setw(2) << setfill('0') << h << ":" << setw(2) << setfill('0') << m << ":" << setw(2) << setfill('0') << s;
    }
};

// 日期类
class Date : public Time
{
private:
    int y, mth, d;

public:
    Date(int y, int mth, int d, int h, int m, int s) : Time(h, m, s), y(y), mth(mth), d(d) {}

    void print()
    {
        cout << y << "-" << setw(2) << setfill('0') << mth << "-" << setw(2) << setfill('0') << d << " ";
        Time::print();
    }
};

int main()
{
    Time t(20, 50, 12);
    cout << "时间: ";
    t.print();
    cout << endl;

    Date d(2020, 1, 20, 20, 50, 12);
    cout << "日期时间: ";
    d.print();
    cout << endl;

    return 0;
}