// Problem: 数据结构 散列表7.2 调试病毒
// Idea: Store each unique complex number in a hash set and maintain the sums of
// all real and imaginary parts. An additional hash table maps a squared modulus
// to all points that have that modulus, allowing pop to remove a whole group.
// Complexity: O(n) expected time in total and O(n) space.

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

const int OFFSET = 1000;
const int BASE = 2001;

// a,b are in [-1000,1000], so the encoded value is a nonnegative int.
int encodePoint(int a, int b) {
    return (a + OFFSET) * BASE + (b + OFFSET);
}

void decodePoint(int key, int& a, int& b) {
    a = key / BASE - OFFSET;
    b = key % BASE - OFFSET;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    unordered_set<int> points;
    unordered_map<long long, vector<int>> pointsByModulus;
    long long sumA = 0;
    long long sumB = 0;
    int count = 0;

    for (int i = 0; i < n; ++i) {
        string operation;
        cin >> operation;

        if (operation == "insert") {
            int a;
            int b;
            cin >> a >> b;

            int key = encodePoint(a, b);
            if (points.insert(key).second) {
                long long modulus = 1LL * a * a + 1LL * b * b;
                pointsByModulus[modulus].push_back(key);
                sumA += a;
                sumB += b;
                ++count;
                cout << "size = " << count << '\n';
            }
        } else if (operation == "delete") {
            int a;
            int b;
            cin >> a >> b;

            int key = encodePoint(a, b);
            if (points.erase(key) > 0) {
                sumA -= a;
                sumB -= b;
                --count;
                cout << "size = " << count << '\n';
            }
        } else if (operation == "pop") {
            long long modulus;
            cin >> modulus;

            auto bucket = pointsByModulus.find(modulus);
            if (bucket != pointsByModulus.end()) {
                // Deleted points may remain in the bucket. The global set check
                // skips those stale entries without changing the total O(n) work.
                for (int key : bucket->second) {
                    if (points.erase(key) > 0) {
                        int a;
                        int b;
                        decodePoint(key, a, b);
                        sumA -= a;
                        sumB -= b;
                        --count;
                    }
                }
                pointsByModulus.erase(bucket);
            }
            cout << "size = " << count << '\n';
        } else {
            long long value = sumA * sumA + sumB * sumB;
            cout << "value = " << value << '\n';
        }
    }

    return 0;
}
