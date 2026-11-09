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

// 判断两个数是否互质
bool isPrime(int x, int y)
{
    return __gcd(x, y) == 1;
}

void P17011()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end(), greater<int>());
    int res = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (isPrime(nums[i], nums[j]))
            {
                res = max(res, nums[i] + nums[j]);
            }
        }
    }
    cout << res << endl;
}

#ifndef LUOGU_MAIN
int main()
{
    P17011();
    return 0;
}
#endif