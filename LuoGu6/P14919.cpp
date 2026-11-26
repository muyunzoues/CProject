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
const int MAXN = 100005;
vector<int> children[MAXN];
long long c[MAXN];    // 染色代价
long long cost[MAXN]; // 子树最小覆盖代价
void dfs(int u)
{
    if (children[u].empty())
    {
        cost[u] = c[u];
        return;
    }
    long long sum = 0;
    for (int i : children[u])
    {
        dfs(i);
        sum += cost[i];
    }
    cost[u] = min(c[u], sum);
}
void P14919()
{
    int n;
    cin >> n;
    vector<vector<int>> children(n + 1); // 动态分配，只占 n+1 个 vector
    vector<long long> c(n + 1);
    vector<long long> cost(n + 1);

    for (int i = 2; i <= n; i++)
    { // 注意：父节点输入从节点 2 开始
        int f;
        cin >> f;
        children[f].push_back(i);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }

    // 逆序递推，不需要 DFS，避免递归栈开销
    for (int i = n; i >= 1; i--)
    {
        if (children[i].empty())
        {
            cost[i] = c[i];
        }
        else
        {
            long long sum = 0;
            for (int v : children[i])
            {
                sum += cost[v];
            }
            cost[i] = min(c[i], sum);
        }
    }

    cout << cost[1] << endl;
}

#ifndef LUOGU_MAIN
int main()
{
    P14919();
    return 0;
}
#endif