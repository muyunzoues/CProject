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
    int m, n, k;
    cin >> m >> n >> k;
    vector<int> a(n);
    vector<vector<int>> group(m + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        group[a[i]].push_back(t);
    }
    for (int i = 1; i <= m; i++)
    {
        sort(group[i].begin(), group[i].end(), greater<int>());
    }
    vector<int> need(m + 1, 0); // 每个知识点最少需要几道题
    long long totalNeed = 0;    // 所有知识点最少题数之和
    bool ok = true;
    for (int i = 1; i <= m; i++)
    {
        long long sum = 0;
        int count = 0;
        for (int x : group[i])
        {
            sum += x;
            count++;
            if (sum >= k)
            {
                break;
            }
        }
        if (sum < k)
        {
            ok = false;
            break;
        }
        need[i] = count;
        totalNeed += count;
    }
    if (!ok)
    {
        cout << -1 << endl;
        return;
    }
    int maxNeed = 0;
    int mx = 0; // 记录哪个知识点需要最多题
    for (int i = 1; i <= m; i++)
    {
        if (need[i] > maxNeed)
        {
            maxNeed = need[i];
            mx = i;
        }
    }
    long long otherNeed = totalNeed - maxNeed; // 其他知识点的必做题总数
    if (otherNeed >= maxNeed - 1)
    {
        // 其他题足够当隔板，所有必做题可以完美交错
        cout << totalNeed << endl;
        return;
    }
    long long extra = 0;
    for (int i = 1; i <= m; i++)
    {
        if (i == mx)
            continue;                            // 主类别自己的额外题不能当隔板（还是同类）
        extra += (int)group[i].size() - need[i]; // 这个知识点的额外题数
    }

    long long gap = maxNeed - 1 - otherNeed; // 还缺多少个隔板
    if (extra >= gap)
    {
        cout << totalNeed + gap << endl; // 借 gap 个额外题当隔板
    }
    else
    {
        cout << -1 << endl; // 隔板不够，无解
    }
}

#ifndef LUOGU_MAIN
int main()
{
    P11246();
    return 0;
}
#endif