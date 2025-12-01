// 字符串处理
// stringstream 的使用，检查小数位数
#include <bits/stdc++.h>
using namespace std;

// 判断输入是否合法
bool isLegal(const string &s, double &x) // 向函数内传递 x 的引用而非 x 的拷贝，直接更改外部的 x
{
    stringstream ss(s);
    ss >> x; // x 为 double 类型

    if (ss.fail()) // 检测输入流状态是否失败（**类型不匹配** / 到达末尾 / 流为空）
        return false;

    string rem;
    ss >> rem;
    if (!rem.empty())
        return false;

    if (x < -1000 || x > 1000)
        return false;

    // []检查小数位数
    int pos = s.find('.');
    if (pos != string::npos) // 找不到字符则返回 string::npos
    {
        int decimals = s.size() - pos - 1;
        if (decimals > 2)
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    vector<string> inputs(n);
    for (int i = 0; i < n; i++)
        cin >> inputs[i];

    double sum = 0;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        double x;
        string s = inputs[i];
        if (!isLegal(s, x))
            cout << "ERROR: " << s << " is not a legal number" << endl;
        else
        {
            sum += x;
            count++;
        }
    }

    if (count == 0)
        cout << "The average of 0 numbers is Undefined" << endl;
    else
        cout << "The average of " << count
             << " number" << (count > 1 ? "s" : "")
             << " is " << fixed << setprecision(2)
             << sum / count << endl;
    return 0;
}
