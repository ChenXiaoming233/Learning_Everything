#include <bits/stdc++.h>

using namespace std;

float prices[25];
struct Time
{
    int month, d, h, m;
    bool isOnline;
    int timeline; // 时间线
    float totalPrice;
    float cost = 0;

    int duration(const Time &other) const
    {
        return other.timeline - timeline;
    }

    float costSingle() const
    {
        float cost = d * 60 * prices[24];
        for (int i = 0; i < h; i++)
        {
            cost += prices[i] * 60;
        }
        cost += prices[h] * m;
        return cost;
    }

    float costBetween(const Time &other) const
    {
        return other.cost - cost;
    }
};
int n;
map<string, vector<Time>> customers;

bool Comparison(const Time &a, const Time &b) // 时间线前后比较函数
{
    return a.timeline < b.timeline;
}

int main()
{
    prices[24] = 0; // ! 注意 初始化！
    for (int i = 0; i < 24; i++) // 读入价位
    {
        cin >> prices[i];
        prices[i] /= 100.0;
        prices[24] += prices[i]; // 全天费用
    }

    cin >> n;

    for (int i = 0; i < n; i++) // 读入记录
    {
        string name;
        cin >> name;
        Time t;
        char colon;
        cin >> t.month >> colon >> t.d >> colon >> t.h >> colon >> t.m;
        string statue;
        cin >> statue;
        t.isOnline = (statue == "on-line");
        t.timeline = t.d * 24 * 60 + t.h * 60 + t.m;
        t.cost = t.costSingle();
        if (customers.count(name) == 0)
        {
            customers.insert({name, vector<Time>()});
        }
        customers[name].push_back(t);
    }

    // 依次处理每个客户
    for (auto it = customers.begin(); it != customers.end(); it++)
    {
        string name = it->first;
        vector<Time> &records = it->second;
        bool hasCalled = false;
        float totalPrice = 0.0;

        sort(records.begin(), records.end(), Comparison);
        for (auto i = 0; i < records.size() - 1; i++)
        {
            if (records[i].isOnline == true and records[i + 1].isOnline == false)
            {
                if (hasCalled == false)
                {
                    cout << name << " ";
                    printf("%02d\n", records[i].month);
                    hasCalled = true;
                }
                int duration = records[i].duration(records[i + 1]);
                float costBetween = records[i].costBetween(records[i + 1]);
                totalPrice += costBetween;
                printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",
                       records[i].d, records[i].h, records[i].m,
                       records[i + 1].d, records[i + 1].h, records[i + 1].m,
                       duration, costBetween);
            }
        }
        if (hasCalled == true)
        {
            printf("Total amount: $%.2f\n", totalPrice);
        }
    }
    return 0;
}
