#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) {
        return 0;
    }

    vector<int> postorder(n);
    vector<int> inorder(n);
    for (int &value : postorder) {
        cin >> value;
    }
    for (int &value : inorder) {
        cin >> value;
    }

    unordered_map<int, int> inorderPosition;
    for (int i = 0; i < n; ++i) {
        inorderPosition[inorder[i]] = i;
    }

    vector<int> preorder;
    preorder.reserve(n);

    auto buildPreorder = [&](auto &&self, int postLeft, int postRight,
                             int inLeft, int inRight) -> void {
        if (postLeft > postRight) {
            return;
        }

        const int rootValue = postorder[postRight];
        preorder.push_back(rootValue);

        const int rootPosition = inorderPosition.at(rootValue);
        const int leftSize = rootPosition - inLeft;

        self(self, postLeft, postLeft + leftSize - 1, inLeft, rootPosition - 1);
        self(self, postLeft + leftSize, postRight - 1, rootPosition + 1, inRight);
    };

    buildPreorder(buildPreorder, 0, n - 1, 0, n - 1);

    cout << "Preorder: ";
    for (int i = 0; i < n; ++i) {
        cout << (i == 0 ? "" : " ") << preorder[i];
    }
    cout << '\n';

    return 0;
}
