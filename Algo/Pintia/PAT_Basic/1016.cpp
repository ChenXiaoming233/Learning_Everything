#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a, b, pa_temp, pb_temp;
    char da, db;
    long int pa, pb;
    cin >> a >> da >> b >> db;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == da)
            pa_temp.push_back(da);
    }
    for (int i = 0; i < b.size(); i++)
    {
        if (b[i] == db)
            pb_temp.push_back(db);
    }
    if (pa_temp.empty()) // 注意 0 情况特判
        pa_temp = "0";
    if (pb_temp.empty())
        pb_temp = "0";
    pa = stoi(pa_temp);
    pb = stoi(pb_temp);
    cout << pa + pb;
    return 0;
}