// ^ 一种贪心思路（增量式）

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> d(n);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }
    for (int i = 1; i < n; i++)
        if (d[i] > d[i - 1]) // 若 d[i] <= d[i - 1] 则可以和前序一起填，不需要额外的次数，**不影响后续**; 反之只能单独填，答案增加 a[i] - a[i-1]
            count += d[i] - d[i - 1];
    cout << count + d[0]; // d[0] 代表了无论如何都得做的底层工作量
    return 0;
}