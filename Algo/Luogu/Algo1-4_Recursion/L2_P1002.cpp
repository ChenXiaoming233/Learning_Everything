#include <iostream>
#include <vector>
#include <algorithm>

#define MAXN 22

using namespace std;

long long f[MAXN][MAXN] = {0};
int ctrl[MAXN][MAXN], n, m, hx, hy; // n m 为网格大小，hx hy 为马所在的位置
int d[9][2] = {{0, 0}, {1, 2}, {1, -2}, {-1, 2},{-1,-2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}}; // 马的控制点与马的相对位置

int main()
{
    cin >> n >> m >> hx >> hy;

    // 将马的控制点由与马的相对位置转为网格中的绝对位置
    for (int i = 0; i < 9; i++)
    {
        int tmpx = hx + d[i][0]; // 第9个元素的第1个数
        int tmpy = hy + d[i][1];
        if (tmpx >= 0 and tmpx <= n and tmpy >= 0 and tmpy <= m) // 判断是否在棋盘范围内
        {
            ctrl[tmpx][tmpy] = 1;
        }
    }

    f[0][0] = 1 - ctrl[0][0]; // 若原点为马的控制点 则初始路径数量为0
    
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (ctrl[i][j])
                continue; // 控制点值为1，进入分支跳过
            if (i != 0) // 判断不为边界
                f[i][j] += f[i - 1][j];
            if (j != 0)
                f[i][j] += f[i][j - 1];
        }
    }
    cout << f[n][m];
    return 0;
}