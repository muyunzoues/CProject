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

void P14920()
{
    long long n, k;
    cin >> n >> k;
    vector<int> a(505);
    vector<int> c(505);
    vector<long long> dp(250005);
    int sum = 0;
    for (int i = 1; i <= 250000; i++)
    {
        dp[i] = 1e18;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> c[i];
        sum += a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = sum; j >= a[i]; j--)
        {
            dp[j] = min(dp[j], dp[j - a[i]] + c[i]);
        }
    }
    for (int i = sum; i >= 0; i--)
        if (dp[i] <= k)
        {
            cout << i << endl;
            break;
        }
}

#ifndef LUOGU_MAIN
int main()
{
    P14920();
    return 0;
}
#endif