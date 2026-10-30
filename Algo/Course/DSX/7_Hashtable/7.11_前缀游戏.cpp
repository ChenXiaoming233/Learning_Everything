/*
Problem: DSX 7.11 Prefix Game

Given n strings, answer m queries. For each query, output how many of the
given strings have that query string as a prefix.

Idea:
Build a trie. Each node stores how many inserted strings pass through it, so
the count at the node reached by a query is exactly its answer.

The trie uses adjacency lists instead of a 26-int array per node. A full
26-array trie can use about 150 MB at the maximum input size, which exceeds
the 102400 KB memory limit.

Complexity:
O(26 * total input length) time in the worst case, which is O(total input
length) with the fixed alphabet size. O(total input length) memory.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    int head = -1;
    int count = 0;
};

struct Edge {
    int to;
    int next;
    char ch;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Node> nodes(1);
    vector<Edge> edges;

    // At most 50000 * 30 characters can create trie edges.
    nodes.reserve(1500001);
    edges.reserve(1500000);

    auto findChild = [&](int node, char ch) {
        for (int edge = nodes[node].head; edge != -1; edge = edges[edge].next) {
            if (edges[edge].ch == ch) {
                return edges[edge].to;
            }
        }
        return -1;
    };

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;

        int node = 0;
        ++nodes[node].count;

        for (char ch : s) {
            int child = findChild(node, ch);
            if (child == -1) {
                child = static_cast<int>(nodes.size());
                nodes.emplace_back();
                edges.push_back({child, nodes[node].head, ch});
                nodes[node].head = static_cast<int>(edges.size()) - 1;
            }

            node = child;
            ++nodes[node].count;
        }
    }

    int m;
    cin >> m;

    while (m--) {
        string query;
        cin >> query;

        int node = 0;
        for (char ch : query) {
            node = findChild(node, ch);
            if (node == -1) {
                break;
            }
        }

        cout << (node == -1 ? 0 : nodes[node].count) << '\n';
    }

    return 0;
}
