// LC40 - 组合Ⅱ
// #回溯 #组合 #无序 #元素可重不可复选

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> track;
    int trackSum = 0;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // 先排序，让相同的元素靠在一起
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, 0, target);
        return res;
    }

    void backtrack(vector<int>& nums, int start, int target) {
        // base case，达到目标和，找到符合条件的组合
        if(trackSum == target) {
            res.push_back(track);
            return;
        }
        // base case，超过目标和，直接结束
        // ! 注意 base case 尽量选取相同维度，避免漏判
        if(trackSum > target) {
            return;
        }

        for(int i = start; i < nums.size(); i++) {
            // 剪枝逻辑，值相同的树枝只遍历第一条
            // ! 注意 i > start 不可少，将剪枝限制在同一层中
            if(i > start && nums[i] == nums[i-1]) {
                continue;
            }
            track.push_back(nums[i]);
            trackSum += nums[i];
            backtrack(nums, i+1, target);
            track.pop_back();
            trackSum -= nums[i];
        }
    }
};