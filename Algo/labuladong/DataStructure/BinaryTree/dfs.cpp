#include <bits/stdc++.h>

using namespace std;

// 基本二叉树节点
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 二叉树的递归遍历框架
void traverse(TreeNode *root)
{
    if (root == nullptr)
    {
        return; // 如果到达叶部，返回上层
    }

    // 前序位置，即 root 指针在树上移动的顺序

    traverse(root->left); // 先向左递归

    // 中序位置，在节点的左子树完全遍历后执行

    traverse(root->right); // 再向右递归

    // 后序位置，在节点的所有子树完全遍历后执行
}

int main()
{
    return 0;
}