// LC47 - 全排列Ⅱ
// #回溯 #排列 #有序 #元素可重不可复选

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> res;
    vector<int> track;
    vector<bool> used;

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        // 先排序，让相同的元素靠在一起
        sort(nums.begin(), nums.end());
        used = vector<bool>(nums.size(), false);
        backtrack(nums);
        return res;
    }

    void backtrack(vector<int> &nums)
    {
        if (track.size() == nums.size())
        {
            res.push_back(track);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (used[i])
            {
                continue;
            }
            // 剪枝逻辑，固定相同的元素在排列中的相对位置
            // ! 注意 i > 0 不可少
            // 保证相同元素在排列中的相对位置保持不变；如果前面的相邻的相等元素没有用过，则跳过；保证 2' 只在 2 已被使用时才被选择，2'' 只在 2' 已被使用时才会被选择
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false)
            {
                continue;
            }
            track.push_back(nums[i]);
            used[i] = true;
            backtrack(nums);
            track.pop_back();
            used[i] = false;
        }
    }
};