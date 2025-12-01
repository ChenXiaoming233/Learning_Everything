// LC491 - 非递减子序列
// #dfs #回溯 #排序 #有序 #元素可重不可复选

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        backtrack(nums, 0);
        return res;
    }

private:
    vector<vector<int>> res;
    vector<int> track;

    void backtrack(vector<int> &nums, int start)
    {
        if (track.size() >= 2)
        {
            // ! 注意 不要 return 而是继续累计，跳出由后续 for 函数完成，否则会影响更长的结果生长
            res.push_back(track);
        }
        // 用哈希集合防止重复选择相同元素
        unordered_set<int> used;

        for (int i = start; i < nums.size(); i++)
        {
            if (!track.empty() && track.back() > nums[i])
            {
                continue;
            }
            // 保证不要重复使用相同的元素
            if (used.count(nums[i]))
            {
                continue;
            }
            used.insert(nums[i]);
            track.push_back(nums[i]);
            backtrack(nums, i + 1);
            track.pop_back();
        }
    }
};