#include <bits/stdc++.h>

using namespace std;

int n, p;
vector<int> as;
vector<int> bs;

const long long MAXN = 1e5 + 50;
const long long MAXX = 1e10;

double cost(double x)
{
    double sum = 0;
    for (int i = 0; i < MAXX; i++)
    {
        double temp = as[i] * x;
        if (temp > bs[i])
            sum += temp - bs[i];
    }
    return sum;
}

int main()
{
    cin >> n >> p;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        as.push_back(a);
        bs.push_back(b);
    }

    int cost_tot = 0;
    for (int i = 0; i < n; i++)
        cost_tot += as[i];
    if (cost_tot <= p)
        cout << -1;

    int left = -1, right = MAXX; // 右端起点为 1e10
    while(left + 1 != right){
        int mid = (left + right) / 2;
        if()
    }

        return 0;
}