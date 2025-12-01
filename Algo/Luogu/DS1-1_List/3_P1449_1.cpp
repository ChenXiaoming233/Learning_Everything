#include <bits/stdc++.h>

using namespace std;

int main()
{
    stack<int> n;
    int s = 0, x, y;
    string input;
    cin >> input;
    stringstream ss(input);
    char ch;
    do
    {
        ch = ss.get();
        if (ch >= '0' and ch <= '9')
        {
            s = s * 10 + (ch - '0');
        }
        else if (ch == '.')
        {
            n.push(s);
            s = 0;
        }
        else if (ch != '@')
        {
            x = n.top();
            n.pop();
            y = n.top();
            n.pop();
            switch (ch)
            {
            case ('+'):
            {
                n.push(y + x);
                break;
            }
            case ('-'):
            {
                n.push(y - x);
                break;
            }
            case ('*'):
            {
                n.push(y * x);
                break;
            }
            case ('/'):
            {
                n.push(y / x);
                break;
            }
            }
        }
    } while (ch != '@');
    cout << n.top();
}