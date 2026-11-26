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
int cnt;
vector<int> l(100010), r(100010), dep(100010);
vector<bool> full(100010); // 表示是否是满二叉树


void dfs(int x)
{
    // 不存在的节点，默认为完全二叉树与满二叉树
    if (x == 0)
    {
        full[x] = true;
        return;
    }
    dfs(l[x]);
    dfs(r[x]);
    dep[x] = max(dep[l[x]], dep[r[x]]) + 1;
    if (dep[l[x]] == dep[r[x]])
    {
        full[x] = full[l[x]] && full[r[x]];
    }
    if (full[x])
    {
        cnt++;
    }
}

void P15801()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> l[i] >> r[i];
    }
    dfs(1);
    cout << cnt << endl;
}

#ifndef LUOGU_MAIN
int main()
{
    P15801();
    return 0;
}
#endif