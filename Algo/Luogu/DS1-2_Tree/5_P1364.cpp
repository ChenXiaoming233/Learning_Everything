#include <bits/stdc++.h>


#define MAXN 110

int n, ans = 1000000000, vis[MAXN];
struct Node
{
    int left, right, father, value;
} t[MAXN];

int cal(int x, int d)
{
    if (x == 0 or vis[x] != 0)
        return 0; // 保证每个节点只访问一次
    vis[x] = 1;
    return cal(t[x].left, d + 1) + cal(t[x].right, d + 1) + cal(t[x].father, d + 1) + t[x].value * d;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> t[i].value >> t[i].left >> t[i].right;
    for (int i = 1; i <= n; i++)
    {
        t[t[i].left].father = i;
        t[t[i].right].father = i;
    }
    for (int i = 1; i <= n; i++){
        memset(vis, 0, sizeof(vis));
        ans = min(ans, cal(i, 0));
    }
    cout << ans << endl;
    return 0;
}