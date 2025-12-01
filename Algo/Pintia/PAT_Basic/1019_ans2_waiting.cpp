#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    do
    {
        string s = to_string(n);
        while (s.size() < 4)
            s += '0';
        sort(s.begin(), s.end());
        int a = stoll(s);
        sort(s.begin(), s.end(), greater<char>());
        int b = stoll(s);
        n = b - a;
        cout << setfill('0') << setw(4) << b << " - " << setw(4) << a << " = " << setw(4) << n << endl;
    } while (n != 0 && n != 6174);
    return 0;
}