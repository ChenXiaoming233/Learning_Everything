// 排队问题，实际模拟队列
// 关联: 1017

#include <bits/stdc++.h>
using namespace std;

struct costomer
{
    int id, n_t1, n_t2, f_t; // 编号、用于计时器的业务剩余时间、输入的业务所需时间、客户等待 + 办理至离开的总分钟数 (从 8:00 开始计时)
};

bool cmp(costomer c1, costomer c2)
{
    return c1.id < c2.id; // id号升序排列
}

int main()
{
    int N, M, K, Q; // 窗口总数 单队伍最大容量 顾客总数 需查询数
    cin >> N >> M >> K >> Q;
    queue<costomer> q[N]; // 一个（元素为存储costomer结构体的queue）的数组

    int id = 1;
    
    // 先将队列装填满
    int Max = min(N * M, K); // ! 注意 k 有可能小于 n * m
    for (int i = 0; i < Max; i++)
    {
        costomer cos;
        int t;
        cin >> t;
        cos.id = id++;
        cos.n_t1 = cos.n_t2 = t;
        // []小寄巧：循环：i % N 确保分配是轮流的：0, 1, 2, ..., N-1, 0, 1, ...
        int window = i % N;
        q[window].push(cos);
    }
    int now_cos_num = K - Max; // 剩余未处理的顾客

    vector<costomer> fin; // 存放结果
    int t = 0;
    int temp = 0; // 空窗口数
    while (1) // 每次循环都是一分钟，每一分钟所有窗口同时 -1
    {
        t++;
        for (int i = 0; i < N; i++)
        {
            if (!q[i].empty())
            {
                q[i].front().n_t1--;
                if (q[i].front().n_t1 == 0)
                {
                    q[i].front().f_t = t;
                    costomer cos = q[i].front();
                    q[i].pop();         // 完成业务，踢出队列
                    fin.push_back(cos); // 结果序列存放该顾客

                    if (now_cos_num-- > 0) // 如果还有剩余顾客
                    {
                        int x;
                        cin >> x; // 输入客户，压入队列
                        cos.id = id++;
                        cos.n_t1 = cos.n_t2 = x;
                        cos.f_t = 0;
                        q[i].push(cos);
                    }
                }
            }
            else
            { // 队列空了，代表没有后续的人，temp++。
                temp++;
            }
        }
        if (temp == N)
            break; // 如果 temp = 窗口数，则说明无人，返回
    }

    sort(fin.begin(), fin.end(), cmp); // 由于查询输入编号由 1 至 k，故顺序排列便于查找

    for (int i = 0; i < Q; i++) // 处理查询
    {
        int x;
        cin >> x;
        x -= 1;
        if (fin[x].f_t - fin[x].n_t2 >= 540) // 服务开始时刻晚于 17:00 则为超时，服务开始时刻 = 总分钟数 - 所需时间
            cout << "Sorry\n";
        else
            printf("%02d:%02d\n", fin[x].f_t / 60 + 8, fin[x].f_t % 60);
    }

    return 0;
}