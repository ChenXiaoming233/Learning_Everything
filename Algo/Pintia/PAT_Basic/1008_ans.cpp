#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    if (n == 0) return 0;
    m %= n; // 当 m > n 时，循环滚动移动 m 位与移动 m % n 位是等价的
    if (m == 0) {
        for (int i = 0; i < n; i++)
            cout << (i ? " " : "") << nums[i];
        return 0;
    }

    for (int i = n - m; i < n; i++)
        cout << (i == n - m ? "" : " ") << nums[i];
    for (int i = 0; i < n - m; i++)
        cout << " " << nums[i];

    return 0;
}
