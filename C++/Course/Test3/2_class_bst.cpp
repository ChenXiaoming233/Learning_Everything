#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right; // 左节点、右节点
    // 构造函数，初始化 val，左右节点为空
    TreeNode(int v) : val(v), left(NULL), right(NULL) {}
};

class BST
{
public:
    TreeNode *root;

    // 构造函数
    BST()
    {
        root = NULL;
    }

    // 插入节点
    TreeNode *insert(TreeNode *node, int val)
    {
        if (node == NULL) // 找到空位则在此插入
            return new TreeNode(val);
        if (val < node->val) // 小于，往左子树插
            node->left = insert(node->left, val);
        else if (val > node->val) // 大于，往右子树插
            node->right = insert(node->right, val);
        return node; // 返回插入完毕后树的根节点
    }

    // 递归遍历
    void inorder(TreeNode *node)
    {
        if (node == NULL)
            return;
        inorder(node->left); // 左侧先小
        cout << node->val << " ";
        inorder(node->right); // 右侧后大
    }

    // 递归搜索
    bool search(TreeNode *node, int val)
    {
        if (node == NULL) // 完成遍历，不存在
            return false;
        if (val == node->val) // 找到
            return true;
        if (val < node->val) // 更小，往左找
            return search(node->left, val);
        if (val > node->val) // 更大，往右找
            return search(node->right, val);
    }
};

int main()
{
    BST tree;
    // int 类型节点插入
    int arr[] = {6, 9, 2, 5, 1, 7};
    int n = 6;
    for (int i = 0; i < n; i++)
        tree.root = tree.insert(tree.root, arr[i]);

    // 树节点的按顺序输出
    tree.inorder(tree.root);
    cout << endl;

    // 节点搜索
    cout << "搜索 5: " << (tree.search(tree.root, 5) ? "找到" : "未找到") << endl;
    return 0;
}
