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

// 获取小于n的所有质数
vector<int> getPrim(int n)
{
    vector<int> prims;
    vector<bool> isPrim(n + 1, true);
    isPrim[0] = isPrim[1] = false;
    for (int i = 2; i < n; i++)
    {
        if (isPrim[i])
        {
            prims.push_back(i);
            for (long long j = (long long)i * i; j <= n; j += i)
            {
                isPrim[j] = false;
            }
        }
    }
    return prims;
}

void P17455()
{
    int n;
    cin >> n;
    vector<int> nums = getPrim(n);
    int l = 0, r = nums.size() - 1;
    int ans = 0;
    while (l <= r)
    {
        if (nums[l] + nums[r] == n)
        {
            ans++;
            l++;
            r--;
        }
        else if (nums[l] + nums[r] < n)
        {
            l++;
        }
        else
        {
            r--;
        }
    }
    cout << ans << endl;
}

#ifndef LUOGU_MAIN
int main()
{
    P17455();
    return 0;
}
#endif