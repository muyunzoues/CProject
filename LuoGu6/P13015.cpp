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

void P13015()
{
    int n;
    cin >> n;
    int a[1005];
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int dp[1005] = {0}; // dp[0] = 0，0个人价值为0

    // 外层枚举容量 i (总人数)，内层枚举最后一个小组的人数 j
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i] = max(dp[i], dp[i - j] + a[j]);
        }
    }

    cout << dp[n] << endl;
}

#ifndef LUOGU_MAIN
int main()
{
    P13015();
    return 0;
}
#endif