// LC45 - 跳跃游戏Ⅱ
// #贪心

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        if (nums.size() <= 1)
        {
            return 0;
        }
        int n = nums.size();
        // 第 jumps 步可以跳到索引区间 [i, end]
        int end = 0, jumps = 0;
        // 在 [i, end] 区间内，最远可以跳到的索引是 farthest
        int farthest = 0;
        for (int i = 0; i < n - 1; i++)
        {
            farthest = max(nums[i] + i, farthest); // 计算从索引 i 处起跳可以跳到的最远索引
            if (i == end)
            {
                // [i, end] 区间是 jumps 步可达的索引范围，现在已经遍历完 [i, end] 即扫描完了当前层
                jumps++;               // 所以需要再跳一步进入下一层
                end = farthest;        // 并更新下一层的边界
                if (farthest >= n - 1) // 如果已经可以到达终点，则可以直接返回
                {
                    return jumps;
                }
            }
        }
        // 如果无法到达终点，则返回 -1
        return -1;
    }
};