#include <array>
#include <iostream>
#include <string>

using namespace std;

struct Node {
    char value = '\0';
    int left = -1;
    int right = -1;
};

struct TreeInfo {
    int root = -1;
    int size = 0;
};

TreeInfo readTree(array<Node, 10> &tree) {
    int n;
    cin >> n;

    array<bool, 10> hasParent{};
    for (int i = 0; i < n; ++i) {
        string leftText;
        string rightText;
        cin >> tree[i].value >> leftText >> rightText;

        tree[i].left = (leftText == "-") ? -1 : stoi(leftText);
        tree[i].right = (rightText == "-") ? -1 : stoi(rightText);

        if (tree[i].left != -1) {
            hasParent[tree[i].left] = true;
        }
        if (tree[i].right != -1) {
            hasParent[tree[i].right] = true;
        }
    }

    int root = -1;
    for (int i = 0; i < n; ++i) {
        if (!hasParent[i]) {
            root = i;
            break;
        }
    }

    return {root, n};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    array<Node, 10> firstTree{};
    array<Node, 10> secondTree{};

    const TreeInfo first = readTree(firstTree);
    const TreeInfo second = readTree(secondTree);

    if (first.size != second.size) {
        cout << "No\n";
        return 0;
    }
    if (first.size == 0) {
        cout << "Yes\n";
        return 0;
    }

    auto isomorphic = [&](auto &&self, int firstRoot, int secondRoot) -> bool {
        if (firstRoot == -1 || secondRoot == -1) {
            return firstRoot == secondRoot;
        }
        if (firstTree[firstRoot].value != secondTree[secondRoot].value) {
            return false;
        }

        const Node &a = firstTree[firstRoot];
        const Node &b = secondTree[secondRoot];

        return (self(self, a.left, b.left) && self(self, a.right, b.right)) ||
               (self(self, a.left, b.right) && self(self, a.right, b.left));
    };

    cout << (isomorphic(isomorphic, first.root, second.root) ? "Yes\n" : "No\n");
    return 0;
}