#include <bits/stdc++.h>

using namespace std;

struct Apple
{
    int x;
    int y;
    bool operator<(const Apple &other) const
    {
        if (y != other.y)
            return y < other.y;
        else
            return x < other.x;
    }
};

int main()
{
    int n, s, a, b;
    int count = 0;
    cin >> n >> s;
    cin >> a >> b;
    vector<Apple> aps; // !注意使用 push_back 向 vector 添加参数时使用无参构造
    for (int i = 0; i < n; i++)
    {
        Apple apple;
        cin >> apple.x >> apple.y;
        if (apple.x <= a + b)
        {
            aps.push_back(apple);
        }
    }
    sort(aps.begin(), aps.end());
    for (int i = 0; i < aps.size(); i++) // 保证力气 s 用完前就摘完了所有苹果时 aps[i] 不会越界
    {
        if (s >= aps[i].y)
        {
            s -= aps[i].y;
            count++;
        }
        else
            break;
    }

    cout << count;
    return 0;
}