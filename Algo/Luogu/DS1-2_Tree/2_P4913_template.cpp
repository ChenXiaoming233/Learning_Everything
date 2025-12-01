#include <bits/stdc++.h>

using namespace std;

int n;
const int MAXN = 1e6 + 6;

struct Node{
    int l, r;
}tree[MAXN];

int dfs(int x){
    if(x == 0) return 0; // 递归深入，直到空节点则返回 0
    return max(dfs(tree[x].l),dfs(tree[x].r)) + 1; // 每经过一层则深度 +1，选取最大值保证最深深度
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> tree[i].l >> tree[i].r;
    }
    cout << dfs(1);
    return 0;
}