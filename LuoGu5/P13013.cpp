#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;
long long n, m, a, b;

bool check(long long k)
{
    if (k == 0)
        return true;

    // 设方案一用 x 份，方案二用 k-x 份
    // 课堂券消耗：a*x + b*(k-x) <= n
    // 作业券消耗：b*x + a*(k-x) <= m
    // 整理得：
    // (a-b)*x <= n - b*k
    // (b-a)*x <= m - a*k

    long long low = 0, high = k;

    if (a == b)
    {
        // 两种方案消耗一样，直接看是否够
        return a * k <= n && a * k <= m;
    }

    if (a > b)
    {
        // 交换 a, b 和 n, m，保证 a <= b，方便处理不等式方向
        swap(a, b);
        swap(n, m);
    }

    // 此时 a < b
    // (a-b) < 0，所以 (a-b)*x <= n - b*k 等价于 x >= (b*k - n) / (b-a) 向上取整
    // (b-a) > 0，所以 (b-a)*x <= m - a*k 等价于 x <= (m - a*k) / (b-a) 向下取整
    long long lower1 = 0;
    if (b * k > n)
    {
        lower1 = (b * k - n + (b - a) - 1) / (b - a); // 向上取整
    }
    else
    {
        lower1 = 0;
    }

    long long upper1 = k; // x 本身不超过 k
    if (a * k > m)
    {
        // m - a*k < 0，说明 x 需要满足 (b-a)*x <= 负数，不可能
        return false;
    }
    long long upper2 = (m - a * k) / (b - a); // 向下取整

    long long L = max(lower1, 0LL);
    long long R = min({upper1, upper2, k});

    return L <= R;
}
// 先假设全部卖给B，得到总的res，然后计算每个C-B的差值，排序后取前n个最大的差值，加到res上，就能得到最终的最大值
void P13013()
{
    cin >> n >> m >> a >> b;

    if (a == b)
    {
        cout << min(n, m) / a << endl;
        return;
    }

    // 二分上界：最多能换的份数不会超过 min(n/a, m/a) 或 min(n/b, m/b)
    long long left = 0, right = min(n / a, m / a);
    right = max(right, min(n / b, m / b));
    right = min(right, min(n, m)); // 保险上界

    long long ans = 0;
    while (left <= right)
    {
        long long mid = left + (right - left) / 2;
        if (check(mid))
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    cout << ans << endl;
}

#ifndef LUOGU_MAIN
int main()
{
    P13013();
    return 0;
}
#endif