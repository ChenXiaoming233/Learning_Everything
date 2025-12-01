// LC78 - 子集
// #回溯 #子集 #无序 #元素无重不可复选

#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    vector<vector<int>> res; // 结果：收集的所有子集
    vector<int> track;       // 当前路径：已选择的元素

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        backtrack(nums, 0);
        return res;
    }

    // 遍历子集问题的回溯树
    void backtrack(vector<int> &nums, int start)
    {

        // 子集的每条路径（无论选择多少）都算一个完整答案 (e.g. [][1][1,2][1,2,3])
        res.push_back(track);

        // 回溯算法框架，每次循环代表在当层的不同选择
        for (int i = start; i < nums.size(); i++)
        {
            // 无 base case, 当 start == nums.length 时，叶子节点的值会被装入 res，但 for 循环不会执行，结束递归

            // 做选择
            track.push_back(nums[i]);
            // 每次递归代表深入下一层 
            // start 参数控制遍历的起始位置，令下一层遍历在 i + 1 开始；同时保证元素之间的相对顺序不变，以防止出现重复的子集
            backtrack(nums, i + 1);
            // 撤销选择
            track.pop_back();
        }
    }
};