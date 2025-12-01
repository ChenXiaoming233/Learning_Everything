#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct person
{
    int num, t;
} people[1001];

bool cmp(person x, person y)
{
    if (x.t != y.t)
    {
        return x.t < y.t;
    }
    else
    {
        return x.num < y.num;
    }
}
int main()
{
    int n, i;
    long long totalT = 0; // 如果你的变量采用了ll且最后变成一大串代码正常运行不太可能产生的数，那可能是你没有初始化...
    long long currentT = 0;
    cin >> n;
    people[0].num = 0;
    for (i = 1; i <= n; i++)
    {
        people[i].num = i;
        cin >> people[i].t;
    }
    people[0].t = 0;
    sort(people + 1, people + n + 1, cmp);
    for (i = 1; i <= n; i++)
    {
        currentT += people[i - 1].t; // 前序每个人的打水时间的累积是后一个人的等待时间
        totalT += currentT;          // 每个人的等待时间累计是所有人的等待时间
        if (i <= n - 1)
        {
            cout << people[i].num << " ";
        }
        else
        {
            cout << people[i].num << endl;
        }
    }
    printf("%.2f", 1.0 * totalT / n);
    return 0;
}