#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int f[1000];
    f[1] = 1;
    f[2] = 2;
    for (int i = 3; i <= N; i++)
    {
        f[i] = f[i - 2] + f[i - 1];
    }
    cout << f[N];
    return 0;
}