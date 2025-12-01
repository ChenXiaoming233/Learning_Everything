#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a, q = "";
    int b, r = 0;
    cin >> a >> b;
    for (char a1 : a)
    {
        r = r * 10 + a1 - '0';
        q += r / b + '0';
        r %= b;
    }
    while (!q.empty() and q.front() == '0')
        q.erase(q.begin());
    cout << (q.size() == 0 ? "0" : q) << " " << r;
    return 0;
}