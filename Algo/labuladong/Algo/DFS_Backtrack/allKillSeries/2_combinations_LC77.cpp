// LC77 - 组合
// #回溯 #组合 #无序 #元素无重不可复选

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> track;

    vector<vector<int>> combine(int n, int k) {
        backtrack(1, n, k);
        return res;
    }

    void backtrack(int start, int n, int k) {
        // base case: 遍历到第 k 层，收集当前节点的值
        if (k == track.size()) {
            res.push_back(vector<int>(track));
            // return; 同样是不必要的，for 循环会进行拦截
        }

        for (int i = start; i <= n; i++) {
            track.push_back(i);
            backtrack(i + 1, n, k);
            track.pop_back();
        }
    }
};