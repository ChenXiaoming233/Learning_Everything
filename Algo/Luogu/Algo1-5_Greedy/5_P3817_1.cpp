#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    long long x;
    cin >> n >> x;
    vector<long long> box(n);
    long long count = 0;
    for (int i = 0; i < n; i++)
        cin >> box[i];
    for (int i = 1; i < n; i++)
    {
        if (box[i - 1] + box[i] > x)
        {
            count += box[i - 1] + box[i] - x;
            box[i] -= box[i - 1] + box[i] - x;
        }
        if (box[i] < 0)
        {
            box[i] = 0;
        }
    }
    cout << count;
    return 0;
}