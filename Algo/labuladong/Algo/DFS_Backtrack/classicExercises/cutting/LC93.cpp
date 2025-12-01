// LC93 - 复原 ip 地址
// #回溯 #子列 #有序 #元素不可复选 #路径枚举/切分

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<string> res;
    deque<string> track;

    vector<string> restoreIpAddresses(string s)
    {
        backtrack(s, 0);
        return res;
    }

    void backtrack(string &s, int start)
    {
        if (start == s.length() && track.size() == 4)
        {
            // 整个 s 被成功分割为合法的四部分
            res.push_back(join(track, ".")); // 将零散的 track 压制成完整的一段
            return;
        }
        for (int i = start; i < s.length(); i++)
        {
            if (!isValid(s, start, i))
            {
                continue;
            }
            if (track.size() >= 4)
            {
                // 已经分解成 4 部分了，不能再分解了
                break;
            }
            track.push_back(s.substr(start, i - start + 1));
            backtrack(s, i + 1);
            track.pop_back();
        }
    }

    // 判断合法
    bool isValid(string &s, int start, int end)
    {
        int length = end - start + 1;

        if (length == 0 || length > 3)
        {
            return false;
        }

        if (length == 1)
        {
            // 如果只有一位数字，肯定是合法的
            return true;
        }

        if (s[start] == '0')
        {
            // 多于一位数字，但开头是 0，肯定不合法
            return false;
        }

        if (length <= 2)
        {
            // 排除了开头是 0 的情况，那么如果是两位数，怎么着都是合法的
            return true;
        }

        // 现在输入的一定是三位数
        if (stoi(s.substr(start, length)) > 255)
        {
            // 不可能大于 255
            return false;
        }
        else
        {
            return true;
        }
    }

    string join(deque<string> &vec, const string &delim) // 前序传入的是 "." 必须加 const
    {
        string result;
        for (int i = 0; i < vec.size(); ++i)
        {
            result += vec[i];
            if (i < vec.size() - 1)
            {
                result += delim;
            }
        }
        return result;
    }
};