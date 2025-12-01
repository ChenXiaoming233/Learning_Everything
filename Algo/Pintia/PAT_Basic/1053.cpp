// 水
#include <bits/stdc++.h>

using namespace std;

vector<vector<float>> es;

int main()
{
    int n;
    float e, d;
    cin >> n >> e >> d;
    for (int i = 0; i < n; i++)
    {
        float n_temp;
        cin >> n_temp;
        es.push_back(vector<float>());
        for (int j = 0; j < n_temp; j++)
        {
            float e_temp;
            cin >> e_temp;
            es[i].push_back(e_temp);
        }
    }

    int count1 = 0, count2 = 0;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < es[i].size(); j++)
        {
            if (es[i][j] < e)
                count++;
        }
        if (static_cast<float>(count) / es[i].size() > 0.5 and es[i].size() > d)
            count1++;
        else if (static_cast<float>(count) / es[i].size() > 0.5)
            count2++;
    }

    float pre1 = 0, pre2 = 0;
    pre1 = static_cast<float>(count1) / es.size();
    pre2 = static_cast<float>(count2) / es.size();
    pre1 = pre1 * 100;
    pre2 = pre2 * 100;
    cout << fixed << setprecision(1);
    cout << pre2 << "% " << pre1 << "%" << endl;
}