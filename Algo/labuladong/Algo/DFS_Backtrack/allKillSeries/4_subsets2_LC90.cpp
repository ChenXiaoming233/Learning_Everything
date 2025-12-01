// LC90 - 子集Ⅱ
// #回溯 #排列 #无序 #元素可重不可复选

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> res;
    deque<int> track;

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        // 先排序，让相同的元素靠在一起
        sort(nums.begin(), nums.end());
        backtrack(nums, 0);
        return res;
    }

    void backtrack(vector<int> &nums, int start)
    {
        // 前序位置，每个节点的值都是一个子集
        res.push_back(vector<int>(track.begin(), track.end()));

        for (int i = start; i < nums.size(); i++)
        {
            // 剪枝逻辑，由于元素可重，对于值相同的相邻树枝只遍历第一条避免重复
            // ! 注意 i > start 不可少，将剪枝限制在同一层中
            if (i > start && nums[i] == nums[i - 1])
            {
                continue;
            }
            track.push_back(nums[i]);
            backtrack(nums, i + 1);
            track.pop_back();
        }
    }
};