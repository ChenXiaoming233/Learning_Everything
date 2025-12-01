// 利用数组下标使用数组模拟 map  #整数键
#include <bits/stdc++.h>

using namespace std;

double s[1010];

int main()
{
    int k1, k2;
    cin >> k1;
    for (int i = 0; i < k1; i++)
    {
        int x;
        double d;
        cin >> x >> d;
        s[x] += d;
    }

    cin >> k2;
    for (int i = 0; i < k2; i++)
    {
        int x;
        double d;
        cin >> x >> d;
        s[x] += d;
    }

    int num = 0;
    for (int i = 1009; i >= 0; i--)
        if (s[i] != 0)
            num++;

    if (num == 0){
        cout << 0;
    }
    else
    {
        cout << num;
        for (int i = 1009; i >= 0; i--)
        {
            if (s[i] != 0)
                printf(" %d %.1lf", i, s[i]);
        }
    }
    return 0;
}