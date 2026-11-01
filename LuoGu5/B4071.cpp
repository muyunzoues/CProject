#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

struct Item
{
    int p;       // 适配的武器编号
    long long c; // 修改花费
};

void B4071()
{
    int n, m;
    cin >> n >> m;

    vector<vector<long long>> cost(n + 1); // cost[i] 存武器 i 的所有材料花费
    long long base1 = 0;                   // 武器 1 的初始材料数

    for (int i = 0; i < m; i++)
    {
        int p;
        long long c;
        cin >> p >> c;
        if (p == 1)
        {
            base1++;
        }
        else if (p >= 2 && p <= n)
        { // 加范围检查
            cost[p].push_back(c);
        }
    }

    // 对每把武器（2~n）的材料花费升序排序，方便贪心取最小的
    for (int i = 2; i <= n; i++)
    {
        sort(cost[i].begin(), cost[i].end());
    }

    long long ans = LLONG_MAX;

    // 枚举武器 1 最终的目标数量 x
    // 至少是 base1，最多不超过 m（所有材料都给武器 1 也不够 m 那么多，但枚举到 m 安全）
    for (int x = base1; x <= m; x++)
    {
        long long totalCost = 0;
        long long cnt1 = base1; // 武器 1 当前数量
        vector<long long> pool; // 备选池：被强制拿走之外剩下的材料花费

        bool feasible = true;

        // 遍历武器 2 ~ n，强制压制到 x - 1
        for (int i = 2; i <= n; i++)
        {
            int sz = cost[i].size();
            // 需要拿走的数量：让剩下的 <= x - 1
            int needRemove = max(0, sz - (x - 1));

            // 贪心：拿走花费最小的 needRemove 个
            for (int j = 0; j < needRemove; j++)
            {
                totalCost += cost[i][j];
                cnt1++; // 被拿走的材料改成武器 1
            }
            // 剩下的放进备选池
            for (int j = needRemove; j < sz; j++)
            {
                pool.push_back(cost[i][j]);
            }

            // 剪枝：如果当前花费已经超过已知答案，直接放弃这个 x
            if (totalCost >= ans)
            {
                feasible = false;
                break;
            }
        }

        if (!feasible)
            continue;

        // 如果武器 1 还不够 x，从备选池里取最小的补足
        if (cnt1 < x)
        {
            sort(pool.begin(), pool.end());
            int need = x - cnt1;
            for (int j = 0; j < need && j < (int)pool.size(); j++)
            {
                totalCost += pool[j];
            }
            // 如果备选池不够，说明这个 x 不可行
            if (need > (int)pool.size())
            {
                continue;
            }
        }

        ans = min(ans, totalCost);
    }

    cout << ans << endl;
}

#ifndef LUOGU_MAIN
int main()
{
    B4071();
    return 0;
}
#endif