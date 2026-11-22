#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <numeric>
#include <stack>
using namespace std;
const int MAXN = 20005;
vector<int> adj[MAXN];
int sz[MAXN];
int n;
int ans = INT_MAX;

//u节点的子树节点数目加1就等于以u为跟的树的节点是，分开的另一部分就是n-sz[u],差值就是abs(n - 2 * sz[u])，通过深度优先搜索，遍历每一个节点的子树得到
//子树节点数后加1即可。
void dfs(int u, int fa)
{
    sz[u] = 1;
    for (int v : adj[u])
    {
        if (v == u)
        {
            continue;
        }
        dfs(v, u);
        sz[u] += sz[v];
    }
    if (u != 1)
    {
        ans = min(ans, abs(n - 2 * sz[u]));
    }
}

void P17458()
{
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    cout << ans << endl;
}

#ifndef LUOGU_MAIN
int main()
{
    P17458();
    return 0;
}
#endif