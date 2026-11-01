// Problem: 数据结构 散列表7.11 前缀游戏
// Idea: Sort all dictionary strings. Every set of strings sharing a prefix is a
// contiguous range. Binary search the prefix and the lexicographic successor of
// the prefix, then subtract the two positions.
// Complexity: O(n log n * L + m log n * L), where L is the maximum string length.

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string nextPrefix(string prefix) {
    int pos = static_cast<int>(prefix.size()) - 1;
    while (pos >= 0 && prefix[pos] == 'z') 
        --pos;
    
    if (pos < 0) 
        return "";

    ++prefix[pos];
    prefix.resize(pos + 1);
    return prefix;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> words(n);
    for (string& word : words) 
        cin >> word;
    
    sort(words.begin(), words.end());

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        string query;
        cin >> query;

        auto first = lower_bound(words.begin(), words.end(), query);
        string upperPrefix = nextPrefix(query);
        auto last = words.end();
        if (!upperPrefix.empty()) {
            last = std::lower_bound(words.begin(), words.end(), upperPrefix);
        }
        cout << static_cast<int>(last - first) << '\n';
    }

    return 0;
}
