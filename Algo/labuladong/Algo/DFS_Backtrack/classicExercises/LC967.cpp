// LC967 - 连续差相同的数字
// #回溯 #排序 #有序 #元素无重可复选

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> res;
    string track;
    vector<int> numsSameConsecDiff(int n, int k)
    {
        backtrack(n, k);
        return res;
    }

    void backtrack(int n, int k)
    {
        // base case != 剪枝 不要在跳出条件中剪枝！
        if (track.size() == n)
        {
            res.push_back(stoi(track));
            return;
        }
        for (int i = 0; i <= 9; i++)
        {
            // 剪枝 1，第一个数字不能是 0
            if (track.size() == 0 and i == 0)
            {
                continue;
            }
            // 剪枝 2，相邻两个数字的差的绝对值必须等于 k
            if (track.size() > 0 and abs(i - (track.back() - '0')) != k)
            {
                continue;
            }
            track.push_back('0' + i);
            backtrack(n, k);
            track.pop_back();
        }
    }
};