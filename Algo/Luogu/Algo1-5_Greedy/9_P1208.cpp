/*(^-^)*/
#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int n, m, ans;

struct node
{
    int a, b;
} a[5005];

bool cmp(node a, node b)
{
    if (a.a != b.a)
        return a.a < b.a;
    else
        return a.b > b.b;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> a[i].a >> a[i].b;
    sort(a + 1, a + 1 + m, cmp);
    int i = 1;
    while (n) // 每次都是 n--，避免 n 在某一次直接跨越 0 的情况
    {
        if (a[i].b != 0)
        {
            a[i].b--;
            ans += a[i].a;
            n--;
        }
        else
            i++;
    }
    cout << ans;
    return 0;
}
