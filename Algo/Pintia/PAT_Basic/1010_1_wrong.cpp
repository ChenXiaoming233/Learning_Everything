#include <cstdio>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

struct Nums
{
    int a;
    int n;
};
Nums num[1005];
vector<Nums> num2;

int main()
{
    vector<int> num_temp;
    string str;
    string m;
    getline(cin, str);
    stringstream ss(str);
    while (getline(ss, m, ' '))
    {
        int o = stoi(m);
        num_temp.push_back(o);
    }

    int len = num_temp.size() / 2;
    for (int i = 0; i < len; i++)
    {
        num[i].a = num_temp[2 * i];
        num[i].n = num_temp[2 * i + 1];
    }
    for (int i = 0; i < len; i++)
    {
        if (num[i].n != 0)
        {
            Nums t;
            t.a = num[i].a * num[i].n;
            t.n = num[i].n - 1;
            if (t.a != 0)
                num2.push_back(t);
        }
    }

    if (num2.empty())
    {
        cout << "0 0";
    }
    else
    {
        for (int i = 0; i < num2.size(); i++)
        {
            cout << (i != 0 ? " " : "") << num2[i].a << " " << num2[i].n;
        }
    }
    return 0;
}