// LC752 - 打开转盘锁
// #bfs #回溯 #最短路径 #状态搜索

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int openLock(vector<string> &deadends, string target)
    {
        unordered_set<string> visited(deadends.begin(), deadends.end()); // 将 dadends 直接加入 visited 以避开
        if (visited.count("0000"))
            return -1;
        queue<string> q;
        int steps = 0;

        // 装填初始情况
        q.push("0000");
        visited.insert("0000");

        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                string cur = q.front();
                q.pop();
                if (cur == target)
                {
                    return steps;
                }
                for (string neighbor : getNeighbors(cur))
                {
                    if (!visited.count(neighbor))
                    {
                        q.push(neighbor);
                        visited.insert(neighbor);
                    }
                }
            }
            steps++;
        }
        return -1;
    }

    vector<string> getNeighbors(string s)
    {
        vector<string> neighbors;
        for (int i = 0; i < 4; i++)
        {
            neighbors.push_back(plusOne(s, i));
            neighbors.push_back(minusOne(s, i));
        }
        return neighbors;
    }

    string plusOne(string s, int j)
    {
        if (s[j] == '9')
            s[j] = '0';
        else
            s[j] += 1;
        return s;
    }

    string minusOne(string s, int j)
    {
        if (s[j] == '0')
            s[j] = '9';
        else
            s[j] -= 1;
        return s;
    }
};
