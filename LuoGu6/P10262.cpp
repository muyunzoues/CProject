#include <iostream>
#include <vector>
#include <string>
using namespace std;

void P10262()
{
    int p;
    string s;
    cin >> p >> s;

    vector<long long> dp(p, 0), ndp(p, 0);
    long long ans = 0;

    for (char ch : s)
    {
        int d = ch - '0';
        fill(ndp.begin(), ndp.end(), 0);

        // 1. 延长之前所有子串
        for (int r = 0; r < p; r++)
        {
            int nr = (r * 10 + d) % p;
            ndp[nr] += dp[r];
        }

        // 2. 当前位单独成串
        ndp[d % p]++;

        // 3. 统计以当前位结尾、能被 p 整除的子串
        ans += ndp[0];

        // 4. 滚动更新
        dp = ndp;
    }

    cout << ans << endl;
}

#ifndef LUOGU_MAIN
int main()
{
    P10262();
    return 0;
}
#endif