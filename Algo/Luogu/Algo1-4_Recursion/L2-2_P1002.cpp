#include <iostream>
#include <vector>
#include <algorithm>

#define MAXN 22

using namespace std;

long long f[MAXN][MAXN] = {0};
int ctrl[MAXN][MAXN], n, m, hx, hy;
int d[9][2] = {{0, 0}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}}; // 马的控制点与马的相对位置

int main()
{
    cin >> n >> m >> hx >> hy;
    for (int i = 0; i < 9; i++)
    {
        int tmphx = hx + d[i][0];
        int tmphy = hy + d[i][1];
        ctrl[tmphx][tmphy] = 1;
    }

    f[0][0] = 1 - ctrl[0][0];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (ctrl[i][j])
                continue;
            if (i != 0)
                f[i][j] += f[i - 1][j];
            if (j != 0)
                f[i][j] += f[i][j - 1];
        }
    }
    cout << f[n][m];
    return 0;
}