#include <bits/stdc++.h>

using namespace std;

long long l, n, k;
vector<long long> pos;

bool can(long long x)
{
    long long cnt = 0;
    for (int i = 1; i < pos.size(); i++)
        cnt += (pos[i] - pos[i - 1] - 1) / x;
    return cnt <= k;
}

int main()
{
    cin >> l >> n >> k;
    pos.push_back(0);
    for (int i = 0; i < n; i++)
    {
        long long t;
        cin >> t;
        pos.push_back(t);
    }
    pos.push_back(l);

    long long left = 0, right = l + 1;
    while (left + 1 != right)
    {
        long long mid = (left + right) / 2;
        if (can(mid)) // ! 注意等价于 x >= xp
            right = mid;
        else
            left = mid;
    }
    cout << right;
    return 0;
}