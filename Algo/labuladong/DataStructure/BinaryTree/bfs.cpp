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

void levelOrderTraverse(TreeNode *root) // ! 注意 使用指针而非引用
{
    if (root == nullptr)
    {
        return;
    }
    queue<TreeNode *> q; // 当前层节点
    q.push(root);
    
    int depth = 1; // 记录当前遍历到的层数（根节点视为第 1 层）

    while (!q.empty())
    {
        int sz = q.size(); // 长度 sz 一定要在循环开始前保存下来，q.size() 在循环中会变化
        for (int i = 0; i < sz; i++) //  i 记录节点 cur 是当前层的第几个节点
        {
            TreeNode *cur = q.front();
            q.pop();
            // 访问 cur 节点，同时知道它所在的层数
            cout << "depth = " << depth << ", val = " << cur->val << endl;

            // 把 cur 的左右子节点加入队列
            if (cur->left != nullptr)
            {
                q.push(cur->left);
            }
            if (cur->right != nullptr)
            {
                q.push(cur->right);
            }
        }
        depth++;
    }
}