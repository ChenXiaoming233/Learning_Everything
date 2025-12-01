// LC17 - 电话号码的字母
// #回溯 #组合 #无序 #元素不可复选

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<string> res;
    string track;
    unordered_map<char, string> mapping = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

    vector<string> letterCombinations(string digits)
    {
        // 从 digits[0] 开始进行回溯
        backtrack(digits, 0);
        return res;
    }

    void backtrack(string digits, int start)
    {
        if (track.size() == digits.size())
        {
            res.push_back(track);
            return;
        }
        char digit = digits[start];
        for (char c : mapping[digit])
        {
            track.push_back(c);
            backtrack(digits, start + 1);
            track.pop_back();
        }
    }
};