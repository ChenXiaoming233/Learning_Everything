#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> lines;
vector<int> scores;

int main()
{
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        lines.push_back(t);
    }
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        scores.push_back(t);
    }
    sort(lines.begin(), lines.end());
    long long tot = 0;
    for (int i = 0; i < n; i++)
    {
        int line = upper_bound(lines.begin(), lines.end(), scores[i]) - lines.begin();
        if (line == 0)
            tot += lines.front() - scores[i];
        else if (line == m)
            tot += scores[i] - lines.back();
        else
            tot += min({abs(scores[i] - lines[line]), abs(scores[i] - lines[line - 1]),abs(scores[i] - lines[line + 1])});
    }
    cout << tot;
}