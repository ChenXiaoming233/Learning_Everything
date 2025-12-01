
// 或 stl 优先队列

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    vector<int> lines(m);
    vector<int> stus(n);
    for (int i = 0; i < m; i++)
        cin >> lines[i];
    for (int i = 0; i < n; i++)
        cin >> stus[i];
    sort(lines.begin(), lines.end());
    long long ans = 0; // ! 注意最多有 10^5 个学生，每个距离值最多达 10^6, int 可能超限
    for (int i = 0; i < n; i++)
    {
        int a = (lower_bound(lines.begin(), lines.end(), stus[i]) - lines.begin());
        if (a == m) // ! 注意特判比所有分数线都高的情况，防止溢出
            ans += stus[i] - lines.back();
        else if (a == 0) // ! 注意特判比所有分数线都低的情况，防止溢出
            ans += lines.front() - stus[i];
        else
            ans += min(abs(lines[a - 1] - stus[i]), abs(lines[a] - stus[i])); // 分数线与估分相差可高可低，取两个绝对值中的最小值
    }
    cout << ans;
}