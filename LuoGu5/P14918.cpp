#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

const int MAXA = 100000;

void P14918()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    // 1. 筛质数
    vector<bool> isPrim(MAXA + 1, true);
    vector<int> prims;
    isPrim[0] = isPrim[1] = false;
    for (int i = 2; i <= MAXA; i++)
    {
        if (isPrim[i])
        {
            prims.push_back(i);
            for (long long j = (long long)i * i; j <= MAXA; j += i)
            {
                isPrim[j] = false;
            }
        }
    }

    // 2. 质因数分解
    unordered_map<int, vector<int>> primeCount;
    for (int i = 0; i < n; i++)
    {
        int x = nums[i];
        for (int p : prims)
        {
            if ((long long)p * p > x)
                break;
            if (x % p == 0)
            {
                int cnt = 0;
                while (x % p == 0)
                {
                    x /= p;
                    cnt++;
                }
                primeCount[p].push_back(cnt);
            }
        }
        if (x > 1)
        {
            primeCount[x].push_back(1);
        }
    }

    long long ans = 0;

    // 3. 对每个质数求中位数并累加代价
    for (auto &kv : primeCount)
    {
        vector<int> &v = kv.second;
        if (v.empty())
            continue; // 防御性判断

        sort(v.begin(), v.end());

        int m = (int)v.size();
        int zeros = n - m;
        int pos = n / 2;

        int mid;
        if (pos < zeros)
        {
            mid = 0;
        }
        else
        {
            int idx = pos - zeros;
            if (idx < 0 || idx >= m)
            { // 防御性判断
                mid = 0;
            }
            else
            {
                mid = v[idx];
            }
        }

        long long cost = (long long)zeros * mid;
        for (int e : v)
        {
            cost += abs(e - mid);
        }
        ans += cost;
    }

    cout << ans << endl;
}

#ifndef LUOGU_MAIN
int main()
{
    P14918();
    return 0;
}
#endif