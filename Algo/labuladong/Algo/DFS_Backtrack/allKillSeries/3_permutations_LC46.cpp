// LC46 - 排列
// #排列 #无序 #元素无重不可复选

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> track;
    // 由于排列为有序，元素相对位置不再固定，不适用 start 去重，故使用数组标记元素使用
    vector<bool> used;

    vector<vector<int>> permute(vector<int>& nums) {
        used = vector<bool>(nums.size(), false);
        backtrack(nums);
        return res;
    }

    void backtrack(vector<int>& nums) {
        // base case: 到达叶子节点
        if (track.size() == nums.size()) {
            // 收集叶子节点上的值
            res.push_back(track);
            return;
        }
        // 回溯算法标准框架
        for (int i = 0; i < nums.size(); i++) {
            // 已经存在 track 中的元素，不能重复选择
            if (used[i]) {
                continue;
            }
            // 做选择
            used[i] = true;
            track.push_back(nums[i]);
            // 进入下一层回溯树
            backtrack(nums);
            // 取消选择
            track.pop_back();
            used[i] = false;
        }
    }
};