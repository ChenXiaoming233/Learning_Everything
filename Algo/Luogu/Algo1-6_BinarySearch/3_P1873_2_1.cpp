#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> trees;

bool can(int x)
{
    long long tot = 0;
    for (int i = 0; i < n; i++)
    {
        if (trees[i] > x)
            tot += trees[i] - x;
    }
    return tot >= m;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        trees.push_back(t);
    }
    sort(trees.begin(), trees.end());

    int left = 0, right = trees.back();
    while (left + 1 != right)
    {
        int mid = (left + right) / 2;
        if (can(mid))
            left = mid;
        else
            right = mid;
    }
    cout << left;
}