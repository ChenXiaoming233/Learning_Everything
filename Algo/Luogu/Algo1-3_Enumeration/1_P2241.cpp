#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    long long n, m, squ = 0, rec = 0;
    cin >> n >> m;
    for(long long x = 0; x <= n; x++){ // 注意循环变量也应当使用 long long，否则会导致变量溢出
        for(long long y = 0; y <= m; y++){
            long long tmp = min(x, y) + min(y, n - x) + min(m - y, x) + min(n - x, m - y);
            squ += tmp;
            rec += n * m - tmp;
        }
    }
    cout << squ / 4 << " " << rec / 4;
}