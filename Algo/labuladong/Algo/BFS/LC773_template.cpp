// LC773 - 滑动谜题
// #bfs #回溯 #最短路径 #状态搜索 #二维映射

#include <bits/stdc++.h>

using namespace std;


class Solution
{
public:
    int slidingPuzzle(vector<vector<int>> &board)
    {
        string target = "123450";
        // 将 2x3 的数组转化成字符串作为 BFS 的起点
        string start = "";
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                start = start + to_string(board[i][j]);
            }
        }

        queue<string> q;
        unordered_set<string> visited;
        // 装填初始状态
        q.push(start);
        visited.insert(start);

        int step = 0;
        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                string cur = q.front();
                q.pop();
                // 达到目标局面
                if (target == cur)
                {
                    return step;
                }
                // 装填下一层节点，下一层节点由函数直接生成，此处为将数字 0 和相邻的数字交换位置
                for (string neighborBoard : getNeighbors(cur))
                {
                    // 防止走回头路
                    if (visited.count(neighborBoard) == false)
                    {
                        q.push(neighborBoard);
                        visited.insert(neighborBoard);
                    }
                }
            }
            step++;
        }
        return -1;
    }

    vector<string> getNeighbors(string board)
    {
        // 记录一维字符串在二维下的相邻索引
        vector<vector<int>> mapping = {
            {1, 3},    // 0号位置的0可以和1、3交换
            {0, 4, 2}, // 1号位置的0可以和0、4、2交换
            {1, 5},    // 2号位置的0可以和1、5交换
            {0, 4},    // 3号位置的0可以和0、4交换
            {3, 1, 5}, // 4号位置的0可以和3、1、5交换
            {4, 2}     // 5号位置的0可以和4、2交换
        };
        // 找到 0 位置
        int idx = board.find('0');
        // 生成邻居状态
        vector<string> neighbors;
        for (int i = 0; i < mapping[idx].size(); i++) // idx 对应 0 在 idx 号位置；i 对应 0 在此位置的情况下能交换的位置
        {
            int adj = mapping[idx][i]; // adj 为本次循环中与 0 交换位置的位置
            string new_board = swap(board, idx, adj); // 调用 swap() 交换 0 与 adj 位置的数字
            neighbors.push_back(new_board);
        }
        return neighbors; // 收集所有情况后压入数组返回
    }

    string swap(string board, int i, int j)
    {
        char temp = board[i];
        board[i] = board[j];
        board[j] = temp;
        return board;
    }
};