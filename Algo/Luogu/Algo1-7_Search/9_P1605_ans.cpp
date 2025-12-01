#include <bits/stdc++.h>

using namespace std;

int n, m, t, sx, sy, fx, fy;
int g[15][15];   // 记录障碍物
int vis[15][15]; // 记录是否被访问
int cnt = 0, dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

void dfs(int x, int y)
{
    if (x == fx and y == fy)
    {
        cnt++;
        return;
    }
    for (int j = 0; j < 4; j++) // 对四个方向遍历
    {
        int l = x + dx[j];
        int r = y + dy[j];
        if (l >= 1 and r >= 1 and l <= n and r <= m and g[l][r] == false and vis[l][r] == false)
        {
            vis[l][r] = true;
            dfs(l, r);
            vis[l][r] = false;
        }
    }
}

int main()
{
    int t, zx, zy;
    cin >> n >> m >> t >> sx >> sy >> fx >> fy;
    g[sx][sy] = true; // ! 注意 起点应标注为已访问，否则后续可能会被重复访问

    for (int i = 0; i < t; i++)
    {
        cin >> zx >> zy;
        g[zx][zy] = true;
    }
    dfs(sx, sy);
    cout << cnt;
}