#include <bits/stdc++.h>

using namespace std;

double s[1010] = {0};

int main()
{
    int k1, k2;
    cin >> k1;
    for (int i = 0; i < k1; i++)
    {
        int n;
        double a;
        cin >> n >> a;
        s[n] += a;
    }
    cin >> k2;
    for (int i = 0; i < k2; i++)
    {
        int n;
        double a;
        cin >> n >> a;
        s[n] += a;
    }

    int num = 0;
    for (int i = 1009; i >= 0; i--)
    {
        if (s[i] != 0)
            num++;
    }
    if (num == 0)
        cout << 0;
    else
    {
        cout << num;
        for (int i = 1009; i >= 0; i--)
        {
            if (s[i] != 0)
                printf(" %d %.1lf", i, s[i]);
        }
    }
}