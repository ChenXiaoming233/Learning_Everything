// LC131 - 分割回文串
// #回溯 #子列 #有序 #元素不可复选 #路径枚举/切分

// 本题没有真正意义上的“元素选择集”，只是按照索引范围切子串，所以不存在全局去重问题

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> res;
    vector<string> track;
    vector<vector<string>> partition(string s) {
        backtrack(s, 0);
        return res;
    }

    void backtrack(string s, int start){
        if(start == s.size()){
            res.push_back(track);
            return;
        }
        for(int i = start; i < s.size(); i++){
            if(isPalindrome(s, start, i) == false){
                continue;
            }
            track.push_back(s.substr(start, i - start + 1));
            backtrack(s, i + 1);
            track.pop_back();
        }
    }

    // 判定回文串
    bool isPalindrome(string s, int lo, int hi){
        while(lo < hi){
            if(s[lo] != s[hi]){
                return false;
            }
            lo++;
            hi--;
        }
        return true;
    }
};