#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    long long n, m, squ = 0, rec = 0;
    cin >> n >> m;
    for(long long x = 0; x <= n; x++){
        for(long long y = 0; y <= m; y++){
            long long tmp = min(x, y);
            squ += tmp;
            rec += x * y - tmp;
        }
    }
    cout << squ << " " << rec;
}