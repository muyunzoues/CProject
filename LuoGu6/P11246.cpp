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

void P11246()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1);
    for (int i = 0; i <= n; i++)
    {
        dp[i] = i; // 初始化为最坏情况，最坏情况就是i个1加起来
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j * j <= i; j++)
        {
            dp[i] = min(dp[i], dp[i - j * j] + 1); // 状态转移方程
        }
    }
    cout << dp[n] << endl;
}

#ifndef LUOGU_MAIN
int main()
{
    P11246();
    return 0;
}
#endif