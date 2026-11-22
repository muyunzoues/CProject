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
long long maxDist = 0;
struct way
{
    int v;
    long long l;
};
vector<way> ways[100005];
void dfs(int u, int fa, long long curDist)
{
    maxDist = max(maxDist, curDist);
    for (auto &[v, w] : ways[u])
    {
        if (v == fa)
        {
            continue;
        }
        dfs(v, u, curDist + w);
    }
}
//要得到从跟出发到所有节点的路程最短，且最后不返回跟，可以通过所有节点路程的总和*2减去到叶节点最大路程得到，得到从跟到叶的最大路径可以通过深度优先搜索dfs
//记录全局变量maxDist，深搜一次就maxDist加上当前路径，下一次深搜就比较，最后就能获得最大距离。
void P14076()
{
    int n;
    cin >> n;
    long long sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        ways[u].push_back({v, w});
        ways[v].push_back({u, w});
        sum += w;
    }
    dfs(1, 0, 0);
    cout << 2 * sum - maxDist << endl;
}

#ifndef LUOGU_MAIN
int main()
{
    P14076();
    return 0;
}
#endif