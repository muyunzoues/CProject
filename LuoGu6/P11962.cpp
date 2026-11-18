#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 200005;
vector<int> adj[MAXN];
int depth[MAXN];
int cnt[2];   // cnt[0] 偶数层节点数，cnt[1] 奇数层节点数

void dfs(int u, int fa, int d) {
    depth[u] = d;
    cnt[d % 2]++;
    for (int v : adj[u]) {
        if (v == fa) continue;
        dfs(v, u, d + 1);
    }
}

void P11962() {
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0, 0);   // 根节点 1 深度为 0

    for (int i = 1; i <= n; i++) {
        cout << cnt[depth[i] % 2] << " ";
    }
    cout << endl;
}

#ifndef LUOGU_MAIN
int main() {
    P11962();
    return 0;
}
#endif