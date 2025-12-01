#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> part;

// 递归函数：rest = 还剩下多少，start = 可以选择的最小数字
void dfs(int rest, int start)
{
    if (rest == 0)
    {
        // 拆完了，输出结果
        for (int i = 0; i < part.size(); i++)
        {
            if (i > 0)
                cout << "+";
            cout << part[i];
        }
        cout << endl;
        return;
    }

    // 枚举当前要加的数字
    for (int i = start; i <= rest && i < n; i++)
    {
        part.push_back(i);
        dfs(rest - i, i); // 继续拆剩下的部分
        part.pop_back();  // 回溯，撤销刚才的数字
    }
}

int main()
{
    cin >> n;
    dfs(n, 1);
    return 0;
}
