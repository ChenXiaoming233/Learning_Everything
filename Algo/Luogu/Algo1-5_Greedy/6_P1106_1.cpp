#include <bits/stdc++.h>

using namespace std;

int main()
{
    string n;
    int k;
    string result;
    cin >> n >> k;
    for (int i = 0; i < n.size(); i++)
    {
        while (!result.empty() and result.back() > n[i] and k > 0)
        {
            result.pop_back();
            k--;
        }
        result.push_back(n[i]);
    }
    while (k > 0 and !result.empty())
    {
        result.pop_back();
        k--;
    }
    int idx = 0;
    while (result[idx] == '0' and idx < result.size())
        idx++;
    if (idx == result.size())
        cout << 0 << endl;
    else
        cout << result.substr(idx) << endl;

    return 0;
}