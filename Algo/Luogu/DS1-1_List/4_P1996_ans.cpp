#include <bits/stdc++.h>

using namespace std;

int main()
{
    queue<int> q;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }

    while (q.size() != 0) // 剩余不是 1 人时
    {
        for (int i = 1; i < m; i++) // 第 1 个到第 m - 1 个小朋友
        {
            q.push(q.front());
            q.pop(); // 将队首放到队尾模拟圆环
        }
        cout << q.front() << " "; // 第 m 个小朋友
        q.pop();
    }
    return 0;
}