// 间隔分词
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    if (a + b < 0)
        putchar('-');
    string s = to_string(abs(a + b));
    int rest = (s.size() % 3 == 0 ? 3 : s.size() % 3);
    cout << s.substr(0, rest);
    for (int i = rest; i < s.size(); i += 3)
        cout << ',' << s.substr(i, 3);
    return 0;
}