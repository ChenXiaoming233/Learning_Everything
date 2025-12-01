#include <bits/stdc++.h>

using namespace std;

struct Person
{
    int h;
    string name;
    bool operator<(const Person &other) const
    {
        if (h != other.h)
            return h < other.h;
        else
            return name < other.name;
    }
};

int main()
{
    int n, k;
    cin >> n >> k;
    vector<Person> ps;
    vector<vector<Person>> lines;
    for (int i = 0; i < n; i++)
    {
        Person p;
        cin >> p.name >> p.h;
        ps.push_back(p);
    }
    sort(ps.begin(), ps.end());

    int count = n;
    int l = floor(static_cast<float>(n) / k);
    for (int i = 0; i < k; i++)
    {
        lines.push_back(vector<Person>{});
        for (int j = 0; j < l; j++)
        {
            lines[i].push_back(ps[i * l + j]);
            count--;
        }
    }
    while (count)
    {
        lines[k - 1].push_back(ps[n - count - 1]);
        count--;
    }

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < l; j += 2)
        {
            cout << (j == 0 ? "" : " ") << lines[i][(l - j * 2 - 1)].name;
        }
        cout << endl;
        cout << lines[i][0].name << endl;
        for (int j = 1; j <= l; j += 2)
        {
            cout << (j == 1 ? "" : " ") << lines[i][(j * 2 + 3)].name;
        }
    }
}