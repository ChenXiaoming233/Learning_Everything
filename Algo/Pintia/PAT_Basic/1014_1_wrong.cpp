#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<string> s(4);
    for (int i = 0; i < 4; i++)
    {
        cin >> s[i];
    }
    int week, h, m, count;
    char h_temp;
    for (int i = 0; i < max(s[0].size(), s[1].size()); i++)
    { // 若有多个数需要利用 min() 取最大值，则需要 min({a, b, c, d})
        if (s[0][i] == s[1][i] and s[0][i] <= 'G' and s[0][i] >= 'A')
        { // ASCII 中 A == 65, Z == 90; a == 97, z == 122; A + 32 == a
            count++;
            if (count == 1)
                week = s[0][i] - 64;
            if (count == 2 and ((s[0][i] >= '0' && s[0][i] <= '9') || (s[0][i] >= 'A' && s[0][i] <= 'N')))
            {
                h_temp = s[0][i];
                break;
            }
        }
    }
    for (int i = 0; i < min(s[2].size(), s[3].size()); i++)
    {
        if (s[2][i] == s[3][i])
        {
            if ((s[2][i] <= 'Z' and s[3][i] >= 'A') or (s[2][i] <= 'z' and s[3][i] >= 'a'))
            {
                m = i;
                break;
            }
        }
    }

    if (h_temp >= '0' && h_temp <= '9')
        h = h_temp - '0';
    if (h_temp >= 'A' && h_temp <= 'N')
        h = h_temp - 'A' + 10;

    if (week == 1)
        cout << "MON";
    if (week == 2)
        cout << "TUE";
    if (week == 3)
        cout << "WED";
    if (week == 4)
        cout << "THU";
    if (week == 5)
        cout << "FRI";
    if (week == 6)
        cout << "SAT";
    if (week == 7)
        cout << "SUN";
    cout << " " << h << ":" << (m <= 9 ? "0" : "") << m;
}