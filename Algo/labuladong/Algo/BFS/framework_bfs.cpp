#include <bits/stdc++.h>

using namespace std;

using Graph = vector<vector<int>>;

// 返回某个点的所有邻接点（下层点）
vector<int> &neighborsOf(Graph &graph, int node)
{
    return graph[node]; // 每个节点是一个 vector<int>，记录下层点的编号
}

// 从 s 开始 BFS 遍历图的所有节点，且记录遍历的步数
// 当走到目标节点 target 时，返回步数
int bfs(Graph &graph, int s, int target)
{
    vector<bool> visited(graph.size(), false); // 记录遍历过的节点，避免死循环
    queue<int> q;                              // 用队列维护 当前层 待访问的节点
    
    // 装填初始节点
    q.push(s);
    visited[s] = true;
    
    int step = 0; // 记录从 s 开始走到当前节点的步数（即层数）
    while (!q.empty())
    {
        int sz = q.size(); // 记录当前层的节点数量；此处必须记录，后续数量会变化
        for (int i = 0; i < sz; i++)
        {
            int cur = q.front();
            q.pop(); // 录入一个丢一个
            cout << "visit " << cur << " at step " << step << endl;

            // 结束条件
            if (cur == target)
            {
                return step;
            }

            // 将该点的下层节点加入队列；使用 queue 保证后进后出，避免干扰本层节点
            vector<int> &neighbors = neighborsOf(graph, cur);
            for (int i = 0; i < neighbors.size(); i++)
            {
                int to = neighbors[i];
                // 去重
                if (!visited[to])
                {
                    q.push(to);
                    visited[to] = true;
                }
            }
        }
        // ! 注意 不要忘记加步数！
        step++; // 经过一层步数 + 1
    }
    // ! 注意 不要忘记未找到返回 -1!
    return -1;
}