#include <iostream>
#include <memory>
#include <queue>
#include <vector>

using namespace std;

struct Node {
    explicit Node(int nodeValue) : value(nodeValue) {}

    int value;
    Node *left = nullptr;
    Node *right = nullptr;
};

Node *createNode(vector<unique_ptr<Node>> &pool, int value) {
    pool.push_back(make_unique<Node>(value));
    return pool.back().get();
}

Node *insert(Node *root, int value, vector<unique_ptr<Node>> &pool) {
    if (root == nullptr) {
        return createNode(pool, value);
    }

    if (value < root->value) {
        root->left = insert(root->left, value, pool);
    } else {
        root->right = insert(root->right, value, pool);
    }
    return root;
}

Node *eraseValue(Node *root, int value) {
    if (root == nullptr) {
        return nullptr;
    }

    if (value < root->value) {
        root->left = eraseValue(root->left, value);
    } else if (value > root->value) {
        root->right = eraseValue(root->right, value);
    } else if (root->left != nullptr) {
        Node *maximum = root->left;
        while (maximum->right != nullptr) {
            maximum = maximum->right;
        }
        root->value = maximum->value;
        root->left = eraseValue(root->left, maximum->value);
    } else if (root->right != nullptr) {
        Node *minimum = root->right;
        while (minimum->left != nullptr) {
            minimum = minimum->left;
        }
        root->value = minimum->value;
        root->right = eraseValue(root->right, minimum->value);
    } else {
        return nullptr;
    }

    return root;
}

void printLevelOrder(const Node *root) {
    queue<const Node *> nodes;
    if (root != nullptr) {
        nodes.push(root);
    }

    bool first = true;
    while (!nodes.empty()) {
        const Node *node = nodes.front();
        nodes.pop();

        cout << (first ? "" : " ") << node->value;
        first = false;

        if (node->left != nullptr) {
            nodes.push(node->left);
        }
        if (node->right != nullptr) {
            nodes.push(node->right);
        }
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<unique_ptr<Node>> pool;
    pool.reserve(n);
    Node *root = nullptr;

    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        root = insert(root, value, pool);
    }

    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int value;
        cin >> value;
        root = eraseValue(root, value);
    }

    printLevelOrder(root);
    return 0;
}