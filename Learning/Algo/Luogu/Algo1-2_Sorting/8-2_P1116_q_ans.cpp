#include <iostream>

using namespace std;

// 另一种统计逆序对的方式，没看懂 懒得管了
int n, sum;
int main()
{
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < i; ++j)
            if (a[j] > a[i])
                sum++;
    cout << sum;
    return 0;
}

