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

void B3873()
{
    int n, L;
    cin >> n >> L;
    // dp[j] 表示容量达到 j（或超过 j 视为 j）时的最小花费
    vector<long long> dp(L + 1, LONG_LONG_MAX);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        long long c, l;
        cin >> c >> l;
        for (int j = l; j >= 0; j--)
        {
            if (dp[j] == LONG_LONG_MAX)
            {
                continue;
            }
            int nj = min(j + (int)l, L); // 超过 L 的都视为 L
            dp[nj] = min(dp[nj], dp[j] + c);
        }
    }
    if (dp[L] == LONG_LONG_MAX)
    {
        cout << "no solution" << endl;
    }
    else
    {
        cout << dp[L] << endl;
    }
}

#ifndef LUOGU_MAIN
int main()
{
    B3873();
    return 0;
}
#endif