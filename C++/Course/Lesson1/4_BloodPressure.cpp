#include <iostream>
using namespace std;

int main()
{
    int maxn = 0, minn = 0;
    cin >> maxn >> minn;
    int maxPressure = max(maxn, minn);
    cout << "鉴定为 ";
    if (maxPressure >= 160 or minn >= 100)
        cout << "2 期高血压";
    else if (maxPressure >= 140 or minn >= 90)
        cout << "1 期高血压";
    else if ((maxn > 120 and maxn < 140) or (minn > 80 and minn < 90))
        cout << "高血压前期";
    else
        cout << "正常血压";
    return 0;
}