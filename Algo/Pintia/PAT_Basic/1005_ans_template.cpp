// 输出内容空格

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int vis[300005]; // vis[n] = 1 表示该数字再次出现，不再是关键数

void While(int n)
{
    while (n != 1)
    {
        if (n % 2 == 0)
        {
            n /= 2;     // 标记的是 n / 2 后的新的值
            vis[n] = 1; // **所有的奇数在下一步都会变成偶数，故只对偶数进行标记**
        }
        else
        {
            n = n * 3 + 1;
            // vis[n] = 1; // **不能** 标记奇数分支，因为偶数分支可以保证 n / 2 一定小于 n，其覆盖关系永远从大到小，而奇数分支中 3n + 1 大于 n，破坏了覆盖关系
        }
    }
}

int main()
{
    vector<int> v;
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        v.push_back(x);
        While(x);
    }

    sort(v.begin(), v.end(), greater<int>());

    int siz = v.size(); // 避免在循环里每次都调用 v.size()
    int T = 0;          // []控制输出时空格的打印
    for (int i = 0; i < siz; i++)
    {
        if (vis[v[i]] == 0)
        {
            cout << (T == 0 ? "" : " ") << v[i];
            T++;
        }
    }
    return 0;
}