#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

struct Node
{
    int num;
    string col;
    int count;
};

int main()
{
    int n;
    cin >> n;
    vector<map<int, string>> mps(n);
    for (int i = 1; i <= n; i++)
    {
        int m;
        cin >> m;
        for (int i = 1; i <= m; i++)
        {
            string col;
            cin >> col;
            mps[i].insert({i, col});
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int i = 1; i <= mps[i].size(); i++)
        {

        }
    }
    return 0;
}