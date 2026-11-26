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

void P17457()
{
    int n;
    cin >> n;
    vector<long long> nums(n + 1);
    vector<long long> sum(n + 1); // 表示前缀和,用前缀和来简化复杂度
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
        sum[i] = sum[i - 1] + nums[i];
    }
    vector<long long> dp(n + 1);
    dp[1] = nums[1] * nums[1];
    for (int i = 1; i <= n; i++)
    {
        dp[i] = sum[i] * sum[i];
        for (int j = 1; j < i; j++)
        {
            dp[i] = min(dp[i], (dp[j] + (sum[i] - sum[j]) * (sum[i] - sum[j])));
        }
    }
    cout << dp[n] << endl;
}

#ifndef LUOGU_MAIN
int main()
{
    P17457();
    return 0;
}
#endif