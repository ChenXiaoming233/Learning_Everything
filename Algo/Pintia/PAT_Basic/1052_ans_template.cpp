// 字符串处理
#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<string> v[3];
    for (int i = 0; i < 3; i++)
    {
        string s;
        getline(cin, s);
        int find1 = 0, find2 = 0;
        while (1)
        {
            find1 = s.find('[', find1); // 此处 find 为 string 成员函数而非 std::find 泛型算法
            find2 = s.find(']', find2);
            if (find1 == -1 or find2 == -1)
                break;
            v[i].push_back(s.substr(find1 + 1, find2 - find1 - 1));
            find1++; // 防止死循环
            find2++;
        }
    }
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a1, a2, a3, a4, a5;
        cin >> a1 >> a2 >> a3 >> a4 >> a5;
        a1 -= 1, a2 -= 1, a3 -= 1, a4 -= 1, a5 -= 1;
        if (a1 >= v[0].size() or a2 >= v[1].size() or a3 >= v[2].size() or a4 >= v[1].size() or a5 >= v[0].size())
            cout << "Are you kidding me? @\\/@" << endl; // 反斜杠作为转义字符会被吞掉
        else
            cout << v[0][a1] << '(' << v[1][a2] << v[2][a3] << v[1][a4] << ')' << v[0][a5] << endl;
    }
    return 0;
}