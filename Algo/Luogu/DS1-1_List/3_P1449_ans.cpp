#include <bits/stdc++.h>

using namespace std;

stack<int> n;
int s = 0, x, y;
int main()
{
    char ch;
    do
    {
        ch = getchar();
        if (ch >= '0' and ch <= '9') // 处理多位数字
            s = s * 10 + (ch - '0'); // 将 ASCⅡ 码转换为整数
        else if (ch == '.')
        {
            n.push(s);
            s = 0;
        }
        else if (ch != '@')
        // ! 注意 @ 出现时 stack 中只剩下了一个数，如果 @ 进入 else 则会导致两次 pop() 进而引发 stack 的 RE
        {
            x = n.top();
            n.pop();
            y = n.top();
            n.pop();
            switch (ch)
            {
            case '+':
                n.push(x + y);
                break;
            case '-':
                n.push(y - x);
                break;
            case '*':
                n.push(x * y);
                break;
            case '/':
                n.push(y / x);
                break;
            }
        }
    } while (ch != '@'); // ! 注意 判断的是上一次读取后的 ch，新的 ch 仍未读入，最后的 @ 会进入一次循环后才令循环体结束

    cout << n.top();
    return 0;
}
