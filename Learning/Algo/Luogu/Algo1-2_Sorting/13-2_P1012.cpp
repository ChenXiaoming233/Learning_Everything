#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// 经典拼数问题，通过字典序进行排序
bool cmp(const string& a, const string& b) {
    return a + b > b + a; 
} // 只需要令**排序后的序列中**任意两个相邻的字符串满足 s[i] + s[i+1] > s[i+1] + s[i] 即可

int main() {
    int n;
    cin >> n;
    vector<string> nums(n); 
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end(), cmp);
    for (int i = 0; i < n; i++) {
        cout << nums[i];
    }
    return 0;
}