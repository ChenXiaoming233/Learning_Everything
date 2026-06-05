#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
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
    srand((unsigned)time(NULL));

    int N = 1000000; // 插入随机数
    int round = 100; // 查找次数

    vector<int> vec;
    BST tree;

    // 生成随机数并插入
    for (int i = 0; i < N; i++)
    {
        int val = rand();
        vec.push_back(val);
        tree.root = tree.insert(tree.root, val);
    }

    // 生成 round 个随机查找目标
    vector<int> targets;
    for (int i = 0; i < round; i++)
        targets.push_back(rand());

    // BST 查找
    int start = clock();
    int bstF = 0;
    for (int i = 0; i < round; i++)
        if (tree.search(tree.root, targets[i]) == true)
            bstF++;
    double bstT = double(clock() - start) / 1000;

    // vector 查找
    sort(vec.begin(), vec.end());
    start = clock();
    int vecF = 0;
    for (int i = 0; i < round; i++)
        if (binary_search(vec.begin(), vec.end(), targets[i]) == true)
            vecF++;
    double vecT = double(clock() - start) / 1000;

    // 输出结果
    cout << "N = " << N << endl;
    cout << "round = " << round << endl;
    cout << "BST 耗时: " << bstT << " 秒" << endl;
    cout << "vector 耗时: " << vecT << " 秒" << endl;
    return 0;
}
