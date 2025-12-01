#include <bits/stdc++.h>

using namespace std;

int main()
{
    string w2 = "";
    cin >> w2;
    vector<char> w;
    vector<char>::iterator pw;
    pw = w.begin();
    int ins = 0;
    for (int i = 0; i < w2.size(); i++)
    {
        if (w2[i] == '[')
            pw = w.begin();
        else if (w2[i] == ']')
            pw = w.end();
        else if (w2[i] == '{')
            pw--;
        else if (w2[i] == '}')
            pw++;
        else if (w2[i] == '-')
        {
            if (ins == 0)
                ins = 1;
            if (ins == 1)
                ins = 0;
        }
        else if (w2[i] == '=')
        {
            pw--;
            w.erase(pw);
        }
        else
        {
            if (ins == 0)
                w.insert(pw, w2[i]);
            if (ins == 1)
                *pw = w2[i]; // 要修改迭代器指向的元素，直接用 *it 进行赋值即可
        }
    }
    for (vector<char>::iterator pw2 = w.begin(); pw2 != w.end(); pw2++)
    {
        cout << *pw2;
    }
    return 0;
}