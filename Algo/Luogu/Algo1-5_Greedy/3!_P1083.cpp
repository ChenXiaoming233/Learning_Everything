#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

struct contest
{
    int l, r;
} con[1000001];

bool cmp(contest x, contest y)
{
    if (x.r != y.r)
    {
        return x.r < y.r; // 先选择参加最先结束的那场比赛，再选择能参加的最早结束的比赛
    }
    else
    {
        return x.l > y.l; // 其实意义不大，在比赛结束时间已最优排序的前提下，对于比赛开始时间的要求仅有不与前者撞档期
    }
}

int main()
{
    long long int n;
    int i, total = 0, finishT = 0;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> con[i].l >> con[i].r;
    }
    sort(con, con + n, cmp);
    for (i = 0; i < n; i++)
    {
        if (finishT <= con[i].l) // 保证档期不撞
        {
            total++;
            finishT = con[i].r;
        }
    }
    cout << total << endl;
    return 0;
}