// ^ 贪心 + 字符串模拟堆栈
// 不能从 9 开始依次删去最大的数，因为存在 0 占位导致数字实质位数更大

#include <bits/stdc++.h>

using namespace std;

int main()
{
    string n;
    int k;
    cin >> n >> k;
    string result;
    for (int i = 0; i < n.size(); i++)
    {
        while (!result.empty() and result.back() > n[i] and k > 0) // !result.empty() 保证栈非空，防止 result.back() 越界访问，result内的第一个元素由后续 push_back 输入
        {
            result.pop_back();
            k--; // 栈内最后一个数大于遇到的数，删除栈内数字
        }
        result.push_back(n[i]); // 栈内最后一个数小于遇到的数，将后者压入栈内
    }
    // 若循环后还有多余的 k，则从末尾删除（循环后 result 中的数已是单调不减）
    while (k > 0 and !result.empty()) // !注意判空！
    {
        result.pop_back();
        k--;
    }

    // [] 去除前导零 + 判空 + 输出结果
    result.erase(0, result.find_first_not_of('0')); // 从下标 0 删除到第一个非 '0' 字符
    if (result.size())
        cout << 0 << endl;
    else
        cout << result << endl;
    return 0;
}
