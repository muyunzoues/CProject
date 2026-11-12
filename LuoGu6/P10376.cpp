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

const int MOD = 1e9 + 7;

void P10376()
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<long long> dp(n + 1, 0);
    for (int i = 0; i <= c && i <= n; i++)
    {
        dp[i] = 1;
    }
    for (int i = c + 1; i <= n; i++)
    {
        long long ways = 0;
        if (i - a <= c)
            ways = (ways + 1) % MOD;
        else
            ways = (ways + dp[i - a]) % MOD;

        if (i - b <= c)
            ways = (ways + 1) % MOD;
        else
            ways = (ways + dp[i - b]) % MOD;

        dp[i] = ways;
    }
    cout << dp[n] << endl;
}

#ifndef LUOGU_MAIN
int main()
{
    P10376();
    return 0;
}
#endif