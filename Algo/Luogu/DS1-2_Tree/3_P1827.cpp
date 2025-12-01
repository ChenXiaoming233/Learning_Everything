#include <bits/stdc++.h>

using namespace std;

string pre, inor;
void work(string pre, string inor)
{
    if (pre.empty())
        return;
    char root = pre[0];
    int k = inor.find(root);
    pre.erase(pre.begin()); // 删去前序序列中的 root 节点，防止死循环
    string leftinor = inor.substr(0, k);
    string rightinor = inor.substr(k + 1); // ! 注意 k + 1 跳过中序中的 root
    // 由于去掉了首位的 root 节点，前序序列的前 k 个数就是左子树
    string leftpre = pre.substr(0, k);
    string rightpre = pre.substr(k);

    // 要输出后序序列，先遍历左子树，再右子树，再根节点
    work(leftpre, leftinor);
    work(rightpre, rightinor);
    cout << root;
}

int main()
{
    cin >> inor >> pre;
    work(pre, inor);
    return 0;
}