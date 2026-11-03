#include <iostream>
using namespace std;

bool isInteresting(long long n)
{
    int cnt = 0;
    while (n > 0)
    {
        cnt += n & 1;
        n >>= 1;
    }
    return cnt % 2 == 1;
}

// 计算 [1, x] 内有趣数之和
long long preSum(long long x)
{
    if (x <= 0)
        return 0;
    long long a = x / 4;           // 完整组的数量
    long long sum = 4 * a * a - a; // 完整组的总和

    // 处理剩余部分（最多 3 个数）
    for (long long i = 4 * a; i <= x; i++)
    {
        if (isInteresting(i))
            sum += i;
    }
    return sum;
}

void P14074()
{
    long long l, r;
    cin >> l >> r;
    cout << preSum(r) - preSum(l - 1) << endl;
}

#ifndef LUOGU_MAIN
int main()
{
    P14074();
    return 0;
}
#endif