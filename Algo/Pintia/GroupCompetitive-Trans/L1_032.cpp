// # *模拟

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    char ch;
    cin >> n >> ch;
    string str, str1;
    getline(cin, str1);
    getline(cin, str);
    if (n >= str.size())
    {
        for (int i = 0; i < (n - str.size()); i++)
        {
            cout << ch;
        }
        cout << str << endl;
    }
    else // ! 注意判断 str.size() > n!
    {
        cout << str.substr(str.size() - n, n);
    }
}
