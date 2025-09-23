#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int f[1010]; // 存储计算结果

int sol(int x)
{
    int ans = 1;
    if (f[x] != -1)
    {
        return f[x]; // 若已有 fx 计算结果则直接调用 避免并行分支各自进行重复计算
    }
    for (int i = 1; i <= x / 2; i++)
    {
        ans += sol(i);
    }
    return f[x] = ans;
}
int main()
{
    cin >> n;
    memset(f, -1, sizeof(f));
    f[1] = 1;
    cout << sol(n) << endl;
    return 0;
}