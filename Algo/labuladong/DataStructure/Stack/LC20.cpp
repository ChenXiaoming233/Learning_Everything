// LC20 - 有效括号

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isValid(string str)
    {
        stack<char> left;
        for (char c : str)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                // 字符 c 是左括号，入栈
                left.push(c);
            }
            else
            {
                // 字符 c 是右括号，则判定能否与栈顶的左括号匹配
                // ! 注意应先检查栈是否为空
                if (!left.empty() && leftOf(c) == left.top())
                {
                    // 匹配则弹出表示通过
                    left.pop();
                }
                else
                {
                    // 和最近的左括号不匹配
                    return false;
                }
            }
        }
        // 是否所有的左括号都被匹配了
        return left.empty();
    }

private:
    char leftOf(char c)
    {
        if (c == '}')
            return '{';
        if (c == ')')
            return '(';
        return '[';
    }
};