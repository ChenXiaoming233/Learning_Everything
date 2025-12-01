#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;  // 指向左子树
    TreeNode *right; // 指向右子树

    TreeNode(int x)
    {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

// 二叉树遍历框架
void traverse(TreeNode *root)
{
    traverse(root->left);
    traverse(root->right);
}

// 二维矩阵遍历框架
void dfs(vector<vector<int>> &grid, int i, int j, vector<vector<bool>> &visited)
{
    int m = grid.size();
    int n = grid[0].size();

    if (i < 0 or j < 0 or i >= m or j >= n) // 越界判断
    {
        return;
    }
    if (visited[i][j]) // 访问判断，避免无限递归
    {
        return;
    }

    // 进入当前节点 (i, j)
    visited[i][j] = true; // 标记访问

    // 进入相邻节点（四叉树）
    // 上
    dfs(grid, i - 1, j, visited);
    // 下
    dfs(grid, i + 1, j, visited);
    // 左
    dfs(grid, i, j - 1, visited);
    // 右
    dfs(grid, i, j + 1, visited);
}