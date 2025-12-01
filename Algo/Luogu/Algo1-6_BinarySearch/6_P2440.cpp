#include <bits/stdc++.h>

using namespace std;

long long n, k;
vector<int> woods;

bool P(int l)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        count += woods[i] / l;
    }
    if (count >= k) // 段数量太多，单段长度太短，区间应向大端移动
        return true;
    else
        return false;
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        woods.push_back(t);
    }
    sort(woods.begin(), woods.end());
    int l = 0, r = woods.back();
    while (l + 1 != r)
    {
        int mid = (l + r) / 2;
        if (P(mid))
            l = mid;
        else
            r = mid;
    }
    if (l < 1)
        cout << 0;
    else
        cout << l;
    return 0;
}