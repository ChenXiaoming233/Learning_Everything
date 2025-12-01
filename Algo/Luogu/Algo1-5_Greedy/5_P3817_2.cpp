#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    long long x;
    cin >> n >> x;
    long long count = 0;
    vector<long long> c(n);
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 1; i < n; i++)
    {
        if (c[i - 1] + c[i] > x)
        {
            count += c[i - 1] + c[i] - x;
            c[i] -= c[i - 1] + c[i] - x;
        }
        if (c[i] < 0)
            c[i] = 0;
    }
    cout << count;
    return 0;
}