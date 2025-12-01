#include <bits/stdc++.h>

#define LL long long

using namespace std;

struct Nums
{
    LL a;
    LL b;
    LL c;
};

int main()
{
    int n;
    cin >> n;
    Nums num[n];
    for (int i = 0; i < n; i++)
    {
        cin >> num[i].a >> num[i].b >> num[i].c;
    }
    for (int i = 0; i < n; i++)
    {
        LL temp;
        temp = num[i].a + num[i].b;
        if (num[i].c < temp)
            cout << "Case #" << i + 1 << ": true" << endl;
        else
            cout << "Case #" << i + 1 << ": false" << endl;
    }
}