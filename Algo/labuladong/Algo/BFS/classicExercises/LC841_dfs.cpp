// LC841 - 钥匙和房间
// #dfs #bfs

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<bool> visited;
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        visited = vector<bool>(rooms.size(), false);
        dfs(rooms, 0);
        visited[0] = true;     // 初始位置也需标记
        for (bool v : visited) // 探索完毕后统计被标记的房间数目
        {
            if (!v)
                return false;
        }
        return true;
    }

    void dfs(vector<vector<int>> &rooms, int room)
    {
        // 无显式跳出，所有钥匙用尽后自动结束
        for (int i = 0; i < rooms[room].size(); i++)
        {
            int key = rooms[room][i];
            if (visited[key] == true)
            {
                continue;
            }
            visited[key] = true;
            dfs(rooms, key);
            // ! 注意 本题无需回溯，只需遍历整棵树
        }
    }
};