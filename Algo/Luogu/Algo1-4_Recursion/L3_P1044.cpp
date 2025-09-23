#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int h[20] = {1, 1}; // 初始化数组，h[0]=1, h[1]=1，其余为0
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        { // j从0遍历到i-1
            h[i] += h[j] * h[i - j - 1];
            // 节点分配：-1 扣除根节点，确保左右子树的节点数之和为 i-1，加上根节点后总节点数为 i
        }
    }
    cout << h[n];
    return 0;
}