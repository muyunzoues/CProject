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

// 统计字符串中连续出现的 "abc" 的次数
vector<int> getNumsabc(string s)
{
    int len = s.length();
    vector<int> res;
    int i = 0;
    while (i + 2 < len)
    {
        int count = 0;
        if (i < len && s.substr(i, 3) == "abc")
        {
            count++;
            int j = i + 3;
            while (j < len && s.substr(j, 3) == "abc")
            {
                count++;
                j += 3;
            }
            res.push_back(count);
            i = j;
        }
        else
        {
            i++;
        }
    }
    return res;
}

void P10721()
{
    int n;
    cin >> n;
    vector<int> numsA(n + 1);
    numsA[0] = 0; // 初始化第一个元素为 0
    for (int i = 1; i <= n; i++)
    {
        cin >> numsA[i];
    }
    int m;
    cin >> m;
    string s;
    cin >> s;
    vector<int> numsabc = getNumsabc(s);
    int maxT = m / 3;                  // 最大可能的块长度
    vector<long long> dp(maxT + 1, 0); // dp[t]：t 个 abc 的最大得分
    for (int t = 1; t <= maxT; t++)
    {
        for (int k = 1; k <= min(t, n); k++)
        {
            dp[t] = max(dp[t], dp[t - k] + numsA[k]);
        }
    }
    long long ans = 0;
    for (int L : numsabc)
    {
        ans += dp[L];
    }
    cout << ans << endl;
}

#ifndef LUOGU_MAIN
int main()
{
    P10721();
    return 0;
}
#endif