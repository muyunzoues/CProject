#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <numeric>
using namespace std;

void P10108()
{
    int n, m;
    cin >> n >> m;
    vector<int> numsa(m);
    vector<int> numsb(n);
    for (int i = 0; i < m; i++)
    {
        cin >> numsa[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> numsb[i];
    }
    // dp[i] 表示到达 i 位置的最大分数
    vector<int> dp(n + 1, INT_MIN);
    dp[0] = numsb[0];
    for (int i = 0; i < n; i++)
    {
        // 如果当前位置不可达，跳过
        if (dp[i] == INT_MIN)
            continue;
        // 尝试使用每个通道
        for (int j = 0; j < m; j++)
        {
            int next = min(i + numsa[j], n);// 超过 n 的都视为 n
            int score = next == n ? 0 : numsb[next];
            dp[next] = max(dp[next], dp[i] + score);// 更新到达 next 位置的最大分数
        }
    }
    cout << dp[n] << endl;
}

#ifndef LUOGU_MAIN
int main()
{
    P10108();
    return 0;
}
#endif