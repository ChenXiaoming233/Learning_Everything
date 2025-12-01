// LC841 - 钥匙和房间
// #dfs #bfs

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    unordered_set<int> pathused;
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        queue<int> q;

        // 装填初始节点
        q.push(0);
        pathused.insert(0);

        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < q.size(); i++)
            {
                int room = q.front();
                q.pop();
                // 无结束条件，直接跳过，循环由 for 循环钥匙串耗尽自动结束
                // 将该点的下层节点加入队列
                for (int i = 0; i < rooms[room].size(); i++)
                {
                    int key = rooms[room][i];
                    // 去重
                    if (pathused.count(key) == false)
                    {
                        pathused.insert(key);
                        q.push(key);
                    }
                }
            }
        }
        for (int i = 0; i < rooms.size(); i++)
        {
            if (pathused.count(i) == false)
            {
                return false;
            }
        }
        return true;
    }
};