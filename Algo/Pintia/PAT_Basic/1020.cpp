#include <bits/stdc++.h>

using namespace std;

struct cake
{
    float n;
    float p;
    float p2;
    bool operator<(const cake &other) const
    {
        return p2 > other.p2;
    }
};
int main()
{
    int n = 0;
    int d = 0;
    double p = 0;
    cin >> n >> d;
    vector<cake> c(n);
    for (int i = 0; i < n; i++)
    {
        cin >> c[i].n;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> c[i].p;
    }
    for (int i = 0; i < n; i++)
    {
        c[i].p2 = c[i].p / c[i].n;
    }
    sort(c.begin(), c.end());
    int i = 0;
    while (d > 0 and i < n) // ! 注意递增循环时为 i 设置范围
    {
        if (c[i].n <= d)
        {
            d -= c[i].n;
            p += c[i].p;
            i++;
            continue;
        }
        else if (c[i].n > d)
        {
            p += c[i].p2 * d;
            d -= d;
        }
    }
    cout << fixed << setprecision(2) << p;
    return 0;
}