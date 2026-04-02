#include <iostream>
#include <cmath>
using namespace std;

int thisIsMyPow(int a, int x)
{
    return pow(a, x);
}

int main()
{
    int a = 0, x = 0;
    cin >> a >> x;
    cout << thisIsMyPow(a, x);
    return 0;
}