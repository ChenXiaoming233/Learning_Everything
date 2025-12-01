// [] lower_bound() 与 upper_bound()
// lower_bound() 返回第一个满足 >= target 的迭代器位置（target 插入在该位置前，使数列有序）
// upper_bound() 返回第一个满足 > target 的迭代器位置（target 插入在该位置后，使数列有序）

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    int t;
    cin >> n >> m;
    vector<int> vec;
    int index;
    while (n--) // !谨慎直接操作存储原始值的变量！
        cin >> t, vec.push_back(t);
    while (m--)
    {
        cin >> t;
        index = lower_bound(vec.begin(), vec.end(), t) - vec.begin(); // -vec.begin() 得到下标（即迭代器差值）
        if (t == vec[index])
            cout << index + 1 << ' ';
        else
            cout << -1 << ' ';
    }
    return 0;
}