#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    int k;
    cin >> s >> k;
    string ans;
    for (int i = 0; i < s.size(); i++)
    {
        while (!ans.empty() and ans.back() > s[i] and k > 0)
        {
            ans.pop_back();
            k--;
        }
        ans.push_back(s[i]);
    }
    while (k > 0 and !ans.empty())
    {
        ans.pop_back();
        k--;
    }
    ans.erase(0, ans.find_first_not_of('0'));
    if (ans.empty())
        cout
            << 0 << endl;
    else
        cout << ans << endl;
    return 0;
}