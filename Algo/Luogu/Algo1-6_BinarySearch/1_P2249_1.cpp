#include <iostream>
#include <algorithm>
#include <cstdio>

#define MAXN 1000010

using namespace std;

int a[MAXN], m, n, q;
int find(int x)
{
    int l = -1, r = n;
    while (l + 1 != r) // 最后 l 和 r 会相等
    {
        int mid = l + r / 2;
        if (a[mid] < x)
            l = mid;
        else
            r = mid;
    }
    return l; // return l or r 取决于搜索条件
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i < m; i++)
    {
        cin >> q;
        cout << find(q) << " ";
    }
    return 0;
}