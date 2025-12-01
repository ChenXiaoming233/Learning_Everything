// 大整数除法

#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a, q = "";
    int b, r = 0;
    cin >> a >> b;
    for (char a1 : a) // []模拟手算除法
    {
        r = r * 10 + a1 - '0'; // [] +- '0' 将字符与数字互相转换
        q += r / b + '0';      // 每次循环将当前商位直接加到字符串末尾
        r %= b;
    }
    while (!q.empty() && q.front() == '0') // []去除前导零
        q.erase(q.begin());
    // q.front() q.back() 返回第一个或最后一个元素数据
    // q.erase() 参数接受元素迭代器
    cout << (q.size() == 0 ? "0" : q) << " " << r;
    return 0;
}
