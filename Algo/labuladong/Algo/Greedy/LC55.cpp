// LC55 - 跳跃游戏
// #贪心

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int farthest = 0; // 当前能到达的最远距离
        int n = nums.size();
        for (int i = 0; i < n - 1; i++)
        {
            // i + nums[i] 代表从 i 格起跳能到达的最远位置；若从前序格中起跳能到达的位置比从 i 格起跳的更远，则不在 i 格起跳
            farthest = max(farthest, i + nums[i]);
            // 意味着过去的所有格子都不能让你达到比 i 更远的地方，说明可能碰到 0 卡住了，剪枝
            if (farthest <= i)
                return false;
        }
        // 只要能到达比终点 n - 1 更远的位置，则一定有办法能到达 n - 1 处
        return farthest >= n - 1;
    }
};