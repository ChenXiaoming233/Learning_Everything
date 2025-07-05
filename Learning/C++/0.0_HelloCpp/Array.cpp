#include <iostream>
using namespace std;

int arr[1001];  // 数组 arr 的下标范围是 [0, 1001)

int main() {
  int n,S=0;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
  }
  for (int i = n; i >= 1; --i) {
    S+=arr[i];
  }
  cout << S << endl;
  return 0;
}