// 四舍五入 细节
#include <bits/stdc++.h>

using namespace std;

double r1, p1, r2, p2;

int main()
{
    cin >> r1 >> p1 >> r2 >> p2;
    double a1, b1, a2, b2, a, b;
    a1 = r1 * cos(p1);
    b1 = r1 * sin(p1);
    a2 = r2 * cos(p2);
    b2 = r2 * sin(p2);
    a = a1 * a2 - b1 * b2;
    b = a1 * b2 + a2 * b1;
    // ! 注意 四舍五入保留两位小数时，计算的结果小于0.005时，就可以判定为是0了，避免残差误差问题
    if (fabs(b) < 0.005)
        b = 0.00;
    if (fabs(a) < 0.005)
        a = 0.00;

    if (b >= 0)
        cout << fixed << setprecision(2) << a << '+' << b << 'i';
    else
        cout << fixed << setprecision(2) << a << '-' << abs(b) << 'i';
    cout << endl;
}