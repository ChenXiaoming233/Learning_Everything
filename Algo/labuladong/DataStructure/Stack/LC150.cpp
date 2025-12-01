// 逆波兰表达式求值

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;
        for (const string &token : tokens)
        {
            // 如果是操作符，弹出两个操作数
            if (token == "+" || token == "-" || token == "*" || token == "/")
            {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                if (token == "+")
                    st.push(a + b);
                // ! 注意 对于减法和除法，顺序别搞反了，第二个数是被除（减）数
                else if (token == "-")
                    st.push(a - b);
                else if (token == "*")
                    st.push(a * b);
                // 整数除法默认向零取整
                else
                    st.push(a / b);
            }
            // 如果是数字，直接入栈
            else
            {

                st.push(stoi(token));
            }
        }
        return st.top();
    }
};
