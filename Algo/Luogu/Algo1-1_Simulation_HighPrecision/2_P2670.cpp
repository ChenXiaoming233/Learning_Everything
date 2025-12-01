#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    char bombs[102][102];
    int count[102][102];
    memset(bombs, 0, sizeof(bombs));
    memset(count, 0, sizeof(count));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> bombs[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (bombs[i][j] == '*')
            {
                count[i - 1][j - 1]++;
                count[i - 1][j]++;
                count[i - 1][j + 1]++;
                count[i][j - 1]++;
                count[i][j + 1]++;
                count[i + 1][j - 1]++;
                count[i + 1][j]++;
                count[i + 1][j + 1]++;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (bombs[i][j] == '*')
            {
                cout << '*';
            }
            else
            {
                cout << count[i][j];
            }
        }
        cout << endl;
    }
}