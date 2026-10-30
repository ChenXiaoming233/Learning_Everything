#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> postorder(n);
    for (int &value : postorder) {
        cin >> value;
    }

    vector<int> levelOrder(n + 1);
    int postorderIndex = 0;

    auto fillLevelOrder = [&](auto &&self, int index) -> void {
        if (index > n) {
            return;
        }

        self(self, index * 2);
        self(self, index * 2 + 1);
        levelOrder[index] = postorder[postorderIndex++];
    };

    fillLevelOrder(fillLevelOrder, 1);

    for (int i = 1; i <= n; ++i) {
        cout << (i == 1 ? "" : " ") << levelOrder[i];
    }
    cout << '\n';

    return 0;
}