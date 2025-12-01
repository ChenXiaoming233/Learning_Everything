#include <bits/stdc++.h>

using namespace std;

int n;
int winner [512], score[512];

void dfs(int x)
{
    if (x >= 1 << n)
        return;
    int l = 2 * x;
    int r = 2 * x + 1;
    dfs(l);
    dfs(r);
    if (score[l] > score[r])
    {
        score[x] = score[l];
        winner[x] = winner[l];
    }
    else
    {
        score[x] = score[r];
        winner[x] = winner[r];
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= 1 << n; i++)
    {
        cin >> score[i + (1 << n) - 1];
        winner[i + (1 << n) - 1] = i;
    }
    dfs(1);
    cout << (winner[1] == winner[2] ? winner[3] : winner[2]);
}