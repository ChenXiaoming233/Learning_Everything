#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int count = 0;
    while (n != 1)
    {
        if (n % 2 == 0)
        {
            n = n / 2;
            count++;
        }
        else
        {
            n = (3 * n + 1) / 2;
            count++;
        }
    }
    cout << count;
    return 0;
}