
// ~AC
#include <bits/stdc++.h>
using namespace std;

#define MAXN 200000 // 上界太小可能会导致段溢出问题
// 素数定理：第n个素数大致满足 pn ~ nln(n)

int a[MAXN];

void Sifting()
{
    a[0] = a[1] = 1;
    int sq = sqrt(MAXN);
    for (int i = 2; i <= sq; i++)
    {
        if (a[i] == 0)
            for (int j = i * i; j < MAXN; j += i)
                a[j] = 1;
    }
}

int main()
{
    int m, n;
    Sifting();
    cin >> m >> n;

    int count = 0, T = 0;
    int a_m = 0, a_n = 0;

    for (int i = 0; i <= MAXN; i++)
    {
        if (a[i] == 0)
        {
            count++;
            if (count == m)
                a_m = i;
            if (count == n)
            {
                a_n = i;
                break;
            }
        }
    }

    for (int i = a_m; i <= a_n; i++)
    {
        if (a[i] == 0)
        {
            cout << (T % 10 == 0 ? "" : " ") << i;
            if (T % 10 == 9)
                cout << endl;
            T++;
        }
    }

    return 0;
}
