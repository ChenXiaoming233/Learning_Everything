// 纯调度问题，只关心窗口空闲时刻，不关心实际队列与成员
// #关联: 1014

#include <bits/stdc++.h>
using namespace std;

struct Customer
{
    int arrive;  // 实际到达时间（秒）
    int process; // 处理时间（秒）
    bool operator<(const Customer &other) const
    {
        arrive < other.arrive;
    }
};

int toSeconds(int h, int m, int s)
{
    return h * 3600 + m * 60 + s;
}

int main()
{
    int N, K;
    cin >> N >> K;

    const int OPEN = 8 * 3600;
    const int CLOSE = 17 * 3600;

    vector<Customer> cus;

    for (int i = 0; i < N; i++)
    {
        int h, m, s, p;
        char c;
        cin >> h >> c >> m >> c >> s >> p;

        int arr = toSeconds(h, m, s);
        if (arr > CLOSE)
            continue;   // 17:00:01 后不服务
        p = min(p, 60); // 最多 60 分钟

        cus.push_back({arr, p * 60});
    }

    if (cus.empty())
    {
        printf("0.0\n");
        return 0;
    }

    sort(cus.begin(), cus.end());

    vector<int> win(K, OPEN); // 表示窗口，存储每个窗口开始空闲的时刻；创建一个长度为 K 的 vector<int>，并把每个元素都初始化为 OPEN
    double totalWait = 0;

    for (int i = 0; i < cus.size(); i++)
    {
        Customer &c = cus[i];
        int idx = min_element(win.begin(), win.end()) - win.begin(); // 找到最早空闲的窗口，idx为窗口号; min_element 返回最小值的迭代器

        if (c.arrive <= win[idx]) // 顾客需要等待
        {
            totalWait += win[idx] - c.arrive; // 总顾客等待时长增加
            win[idx] += c.process;            // 更新该窗口下次空闲时间
        }
        else // 顾客不需要等待
        {
            win[idx] = c.arrive + c.process; // 更新该窗口下次空闲时间
        }
    }

    double avg = totalWait / cus.size() / 60.0;
    printf("%.1f\n", avg);

    return 0;
}
