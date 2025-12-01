#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<long long> woods;

bool can(int x)
{
    int count = 0;
    for (int i = 0; i < n; i++)
        count += woods[i] / x;
    return count >= k;
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
    long long int left = 0, right = woods.back();
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