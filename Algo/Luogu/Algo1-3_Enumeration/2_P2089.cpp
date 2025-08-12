#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define rep(i, a, b) for(int i = a; i <= b; i++)

using namespace std;

// 使用 #define 宏构造语句减少代码量
int main() {
    int n, count = 0;
    vector<string> ans(100000); // 最多有 3^10 = 59049 种排列方法
    cin >> n;
    rep(a, 1, 3) rep(b, 1, 3) rep(c, 1, 3) rep(d, 1, 3) rep(e, 1, 3) rep(f, 1, 3) rep(g, 1, 3) rep(h, 1, 3) rep(i, 1, 3) rep(j, 1, 3){
    // 通过枚举产生的 string 本身已经按照字典序排序
        if (a + b + c + d + e + f + g + h + i + j == n){
            ans[count] = {to_string(a) + " " + to_string(b) + " " + to_string(c) + " " + to_string(d) + " " + to_string(e) + " " + to_string(f) + " " + to_string(g) + " " + to_string(h) + " " + to_string(i)+ " " + to_string(j)};
            // 标答中使用双层数组存储方案编号与配料重量，此处使用 to_string() 将类型为 int 的配料重量全部存入一个 string 元素中
            count++;
        }
    }
    cout << count << endl;
    for(int i = 0; i < count; i++){
        cout << ans[i] << endl;
    }
}