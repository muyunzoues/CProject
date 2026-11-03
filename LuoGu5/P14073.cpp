#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;

// 判断一个数是否为质数
bool is_prime(int x)
{
    if (x == 1)
        return false;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}
void P14073()
{
    int n;
    cin >> n;
    if (n == 1)
    { // 特判：n=1 时只能选 1
        cout << 1 << endl;
        return;
    }
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    int cnt = 0;
    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i])
        {
            cnt++;
            // 把 i 的倍数标记为合数
            for (long long j = (long long)i * i; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    // 答案 = 质数个数 + 1（数字 1 必选）
    cout << cnt + 1 << endl;
}

#ifndef LUOGU_MAIN
int main()
{
    P14073();
    return 0;
}
#endif