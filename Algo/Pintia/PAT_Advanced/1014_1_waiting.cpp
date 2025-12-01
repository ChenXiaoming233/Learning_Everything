#include <bits/stdc++.h>
using namespace std;

int n, m, k, q;

struct custom
{
    int id, time1, time2, count;
    bool operator<(const custom &other) const
    {
        return id < other.id;
    }
} coss[2020];

int main()
{
    cin >> n >> m >> k >> q; // 窗口总数 单队伍最大容量 顾客总数 需查询数
    queue<custom> line[n];
    for (int i = 0; i < n * m; i++)
    {
        int t;
        coss[i].id = i + 1;
        cin >> t;
        coss[i].time1 = coss[i].time2 = t;
        coss[i].count = 0;
    }

    int max = min(n * m, k);
    for (int i = 0; i < max; i++)
    {
        int no = i % n;
        line[no].push(coss[i]);
    }
    int rest = k - max;
    int next = max;
    int time = 0;
    int empty = 0;
    vector<custom> ans;
    while (1)
    {
        time++;
        for (int i = 0; i < n; i++)
        {
            if (!line[i].empty())
            {
                line[i].front().time1--;
                if (line[i].front().time1 == 0)
                {
                    line[i].front().count = time;
                    ans.push_back(line[i].front());
                    line[i].pop();
                    if (rest > 0)
                    {
                        line[i].push(coss[next]);
                        next++;
                        rest--;
                    }
                }
            }
            else
            {
                empty++;
            }
        }
        if (empty == n)
        {
            break;
        }
    }
    sort(ans.begin(), ans.end());

    for (int i = 0; i < q; i++) // 处理查询
    {
        int x;
        cin >> x;
        x -= 1;
        if (ans[x].count - ans[x].time2 > 540) // 服务开始时刻晚于 17:00 则为超时，服务开始时刻 = 总分钟数 - 所需时间
            cout << "Sorry\n";
        else
            printf("%02d:%02d\n", ans[x].count / 60 + 8, ans[x].count % 60);
    }
    return 0;
}