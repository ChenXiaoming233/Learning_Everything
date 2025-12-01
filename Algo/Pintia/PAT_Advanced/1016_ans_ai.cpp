// 复杂模拟 常用STL
// ac 解答来自 ai
#include <bits/stdc++.h>

using namespace std;

// 费率数组，price[24] 存储一天的总费率
double price[25];

// 时间结构体
struct Record
{
    int month, day, hour, minute;
    int totalMinutes; // 从月初开始的分钟数（绝对时间线）
    bool isOnline;

    // 计算时间差（分钟）
    int duration(const Record &other) const
    {
        return other.totalMinutes - totalMinutes;
    }

    // 计算从月初到当前时间的总费用
    double costFromStart() const
    {
        double total = day * 60 * price[24]; // 整天的费用
        for (int i = 0; i < hour; i++)
        {
            total += 60 * price[i]; // 整小时的费用
        }
        total += minute * price[hour]; // 剩余分钟的费用
        return total;
    }

    // 计算两个时间点之间的费用
    double costBetween(const Record &other) const
    {
        return other.costFromStart() - costFromStart();
    }
};

// 定义时间比较排序
bool compareRecords(const Record &a, const Record &b)
{
    return a.totalMinutes < b.totalMinutes;
}

int main()
{
    // 读取费率
    for (int i = 0; i < 24; i++)
    {
        cin >> price[i];
        price[i] /= 100.0;     // 转换为美元
        price[24] += price[i]; // 计算一天总费率
    }

    int n;
    cin >> n;

    // 存储每个客户的记录
    map<string, vector<Record>> customers;

    // 读取所有记录
    for (int i = 0; i < n; i++)
    {
        string name, status;
        Record record;
        char colon; // 使用 colon 存储无用的 ":"

        cin >> name;
        cin >> record.month >> colon >> record.day >> colon >> record.hour >> colon >> record.minute;
        cin >> status;

        record.isOnline = (status == "on-line");
        record.totalMinutes = record.day * 24 * 60 + record.hour * 60 + record.minute;

        customers[name].push_back(record);
    }

    // 处理每个客户
    for (auto it = customers.begin(); it != customers.end(); it++)
    {
        string name = it->first;              // 客户姓名
        vector<Record> &records = it->second; // 加载该客户的记录列表，使用引用以直接加载原数据
        double totalAmount = 0;
        bool hasValidRecords = false;

        // 对同一个客户的所有记录按时间排序，便于后续匹配首尾
        sort(records.begin(), records.end(), compareRecords);

        // 配对 online 和 offline 记录
        for (int i = 0; i < records.size() - 1; i++)
        {
            if (records[i].isOnline && !records[i + 1].isOnline)
            {
                // 找到有效配对
                if (!hasValidRecords) // 第一次找到有效记录，输出客户头信息
                {

                    cout << name << " ";
                    printf("%02d\n", records[i].month);
                    hasValidRecords = true;
                }

                // 计算通话信息
                int duration = records[i].duration(records[i + 1]);
                double cost = records[i].costBetween(records[i + 1]);
                totalAmount += cost;

                // 输出单次通话详情
                printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",
                       records[i].day, records[i].hour, records[i].minute,
                       records[i + 1].day, records[i + 1].hour, records[i + 1].minute,
                       duration, cost);
            }
        }
        // 输出总费用
        if (hasValidRecords)
        {
            printf("Total amount: $%.2f\n", totalAmount);
        }
    }

    return 0;
}