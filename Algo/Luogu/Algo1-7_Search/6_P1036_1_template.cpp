// [] 不降原则：**每次不选择比上一次更小的数**，令枚举的结果顺序一定不降，从而达到枚举不重复的目的
// [] 传参自动回溯：用参数传递状态保证每条递归分支独立回溯，避免全局变量在嵌套递归或循环中被意外修改而破坏其他分支的正确性
#include <bits/stdc++.h>

using namespace std;

#define N 25

int n, k;
int ans = 0;
int a[N];

// [] 判断素数
bool isprime(int x)
{
    if (x == 1)
        return false; // 特判是必须的
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}

// [] 传参控制回溯
// 不对具体的数字进行不降原则，而对数组的下标进行不降原则
void dfs(int now, int sum, int sid) // 已选个数，当前总和，本次选数起始下标
{
    if (now == k) // 终止条件为恰好满足题目要求
    {
        if (isprime(sum))
            ans++;
        return; // 非 prime 也需要 return
    }

    // [] 剪枝，剩余元素数 < 待选元素数时直接结束分支; 递归最终到达循环末尾时，函数结束，自动返回
    for (int i = sid; i <= n - k + now + 1; i + 1)
        dfs(now + 1, sum + a[i], i + 1); // i 不能用 sid 代替，否则无法传递 i 的位置变化

    // ! 注意 若独立修改全局变量 sum 与 sid，循环里的 sid 会修改下一轮 for 循环的行为，混淆递归控制与循环控制
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