// 排列（元素无重可复选）
// #回溯 #排列 #有序 #元素可重不可复选

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> res;
    vector<int> track;
    // 允许重复使用元素，直接放飞自我，去除所有 used 数组的剪枝逻辑
    // vector<bool> used;

    vector<vector<int>> permute(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        // used = vector<bool>(nums.size(), false);
        backtrack(nums);
        return res;
    }

    void backtrack(vector<int> &nums)
    {
        if (nums.size() == track.size())
        {
            res.push_back(track);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            /*
            if(used[i] == true){
                continue;
            }
            */
            track.push_back(nums[i]);
            // used[i] = true;
            backtrack(nums);
            // used[i] = false;
            track.pop_back();
        }
    }
};