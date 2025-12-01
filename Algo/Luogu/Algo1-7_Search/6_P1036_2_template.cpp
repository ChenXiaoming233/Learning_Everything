#include <bits/stdc++.h>

using namespace std;

int n, k;
int ans = 0;
int a[25];

bool isprime(int x)
{
    if (x = 1)
        return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}

// [] 双分支 dfs: 二叉树子集搜索 (0/1 选择), 每个元素都是二选一
void dfs(int now, int sum, int idx)
{
    if (now = k) // 递归深度为 k，即选与不选的决策做了 k 个，不代表选择了 k 个
    {
        if (isprime(sum))
            ans++;
        return;
    }
    if (n - idx + 1 < k - now) // 剪枝：剩余元素数量 < 还需要的元素数量
        return;
    dfs(now + 1, sum + a[idx], idx + 1);
    dfs(now, sum, idx + 1); // ！注意 不选不代表什么都不改变！
    // ! 注意 递归中 **绝不能写 ++ ** ，自增自减运算符会改动变量原有的值
    // 原有写法的循环中的每个 i 相当于选择了 a[i], 跳过的 i 相当于不选
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    dfs(0, 0, 1);
    cout << ans;
    return 0;
}