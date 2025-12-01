// LC39 - 组合总和
// #回溯 #组合 #无序 #元素无重可复选

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> res;
    deque<int> track;
    int trackSum = 0;

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        backtrack(candidates, 0, target);
        return res;
    }

    void backtrack(vector<int> &nums, int start, int target)
    {
        // base case，找到目标和，记录结果
        if (trackSum == target)
        {
            res.push_back(vector<int>(track.begin(), track.end()));
            return;
        }
        // base case，超过目标和，停止向下遍历
        if (trackSum > target)
        {
            return;
        }
        for (int i = start; i < nums.size(); i++)
        {
            trackSum += nums[i];
            track.push_back(nums[i]);
            // start 参数为 i , 令同一元素复可用且避免重复组合
            // ! 注意 start 不可为 0, 否则会令同一元素复用且重复组合
            backtrack(nums, i, target);
            trackSum -= nums[i];
            track.pop_back();
        }
    }
};