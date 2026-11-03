#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;

//求最大公约数
int gcd(vector<int> &nums)
{
    int res = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        res = __gcd(res, nums[i]);
        if(res == 1)
            break;
    }
    return res;
}
void P13014() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // 1. 预处理差值 GCD
    int d = 0;
    for (int i = 1; i < n; i++) {
        d = __gcd(d, abs(a[i] - a[0]));
    }

    // 2. 回答询问
    for (int i = 1; i <= q; i++) {
        // 如果 n=1，d=0，gcd(0, a[0]+i) 就是 a[0]+i 本身
        cout << __gcd(d, a[0] + i) << endl;
    }
}

#ifndef LUOGU_MAIN
int main()
{
    P13014();
    return 0;
}
#endif