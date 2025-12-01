#include <bits/stdc++.h>

using namespace std;

int l, n, m;
vector<long long> rocks;

bool can(long long x)
{
    int count = 0;
    long long last = 0;
    for (int i = 0; i < rocks.size(); i++)
    {
        if (rocks[i] - last < x)
            count++;
        else
            last = rocks[i];
    }
    return count <= m;
}

int main()
{
    cin >> l >> n >> m;
    for (int i = 0; i < n; i++)
    {
        long long t;
        cin >> t;
        rocks.push_back(t);
    }
    rocks.push_back(l);
    sort(rocks.begin(), rocks.end());

    long long left = 0, right = l + 1;
    while (left + 1 != right)
    {
        long long mid = (left + right) / 2;
        if (can(mid))
            left = mid;
        else
            right = mid;
    }
    cout << left;
    return 0;
}