#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int x, a, b, c, m, n;
    cin >> x >> a >> b >> c >> m >> n;
    double result = a * pow(x, m) + b * pow(x, n) + c;
    cout << result;
    return 0;
}