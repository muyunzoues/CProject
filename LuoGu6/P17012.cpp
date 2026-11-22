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
vector<bool> comp(100010); // 表述是否是完全二叉树
vector<bool> full(100010); // 表示是否是满二叉树

//如果一个节点是否是完全二叉树根节点，则它可以是满二叉树根节点，也可以左右子树高度相等且左子树是满二叉树右子树是完全二叉树，也可以是左子树高度等于右子树加1
//且左子树是完全二叉树，右子树是满二叉树。
void dfs(int x)
{
    // 不存在的节点，默认为完全二叉树与满二叉树
    if (x == 0)
    {
        comp[x] = true;
        full[x] = true;
        return;
    }
    dfs(l[x]);
    dfs(r[x]);
    dep[x] = max(dep[l[x]], dep[r[x]]) + 1;
    full[x] = full[l[x]] && full[r[x]] && (dep[l[x]] == dep[r[x]]); // 满二叉树当且仅当左右子树均为满二叉树且深度相同
    if (dep[l[x]] == dep[r[x]])
    {
        comp[x] = full[l[x]] && comp[r[x]];
    }
    else if (dep[l[x]] == dep[r[x]] + 1)
    {
        comp[x] = comp[l[x]] && full[r[x]];
    }
    if (comp[x])
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