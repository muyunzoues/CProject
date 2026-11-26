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

void P15800()
{
    int n;
    cin >> n;

    vector<long long> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];

    // dp[i]：强制选位置 i 时的最大分数
    vector<long long> dp(n + 1, 0);

    // activate[t] 存的是所有 reach[j] == t 的 j 的 dp[j]
    // reach[j] = j + max(1, b[j])
    vector<vector<long long>> activate(n + 2);

    long long best = 0; // 所有已激活的 dp[j] 的最大值（0 表示“不选前驱”）
    long long ans = 0;

    for (int i = 1; i <= n; i++)
    {
        // 1. 激活所有 reach[j] == i 的 j
        for (long long val : activate[i])
        {
            best = max(best, val);
        }

        // 2. 计算 dp[i]：选 i 作为当前结尾
        dp[i] = a[i] + best;
        ans = max(ans, dp[i]);

        // 3. 计算 i 的 reach，等到 reach 时刻再激活 dp[i]
        int reach = i + max(1LL, b[i]);
        if (reach <= n)
        {
            activate[reach].push_back(dp[i]);
        }
        // 如果 reach > n，说明选 i 之后跳不到任何位置，不需要激活
    }

    cout << ans << endl;
}

#ifndef LUOGU_MAIN
int main()
{
    P15800();
    return 0;
}
#endif