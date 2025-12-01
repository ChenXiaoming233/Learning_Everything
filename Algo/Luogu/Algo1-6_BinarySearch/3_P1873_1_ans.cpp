// 非二分答案法

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    long long m;
    cin >> n >> m;
    vector<int> trees;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        trees.push_back(t);
    }
    sort(trees.begin(), trees.end());
    long long h = 0;
    long long sum = 0;
    int num = n;
    while (sum < m)
    {
        sum += (trees[num] - trees[num - 1]) * (n - num);
        // 已砍过了 i 棵树，此时被砍过的 i 棵树的高度均等于第 i + 1 棵树的高度，再砍一棵树（砍第 i + 1 棵）后获得的新高度为（第 i + 1 棵树的高度 - 第 i + 2 棵树的高度）*（i + 1）
        num--;
    }
    num++;
    h = trees[num - 1] + (sum - m) / (n - num); // 防止多砍
    cout << h;
    return 0;
}