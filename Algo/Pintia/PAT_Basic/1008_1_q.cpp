#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> nums(n + m + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    if (n == 0)
        return 0;
    if (m == 0)
    {
        for (int i = 0; i < n; i++)
            cout << (i ? " " : "") << nums[i];
        return 0;
    }

    if (n < m)
    {
        m = m % n;
    }

    for (int i = n - m; i < n; i++)
    {
        cout << (i == n - m ? "" : " ") << nums[i];
    }
    for (int i = 0; i <= n - m - 1; i++)
    {
        cout << (m == n ? "" : " ") << nums[i];
    }

    return 0;
}