#include <iostream>
using namespace std;
const int pic_max=1001;
int arr[pic_max][pic_max];   
int main() {
  int n = 0,m = 0;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> arr[i][j];
    }
  }
  cout << arr[1][1] << endl;
  return 0;
}