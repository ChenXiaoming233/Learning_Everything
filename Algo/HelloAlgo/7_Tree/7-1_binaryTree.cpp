#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
    int val; // 节点的值
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){} // 构造函数    
};

int main() {
    /* 初始化二叉树 */
    // 初始化节点
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n5 = new TreeNode(5);
    TreeNode* P = new TreeNode(6);

    // 构建节点之间的引用（指针）
    n1->left = n2; // 使用 -> 访问成员
    (*n1).right = n3; // n1 是存储在堆上的对象，在栈内存中本质是指针，存储的是内存地址，先解引用再使用 
    n2->left = n4;
    n2->right = n5;

    // 添加节点
    n1->left = P;
    P->left = n2;

    // 删除节点
    n1->left = n2;
    return 0;
}