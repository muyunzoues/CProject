#include <iostream>
#include <vector>
using namespace std;

void B3969()
{
    int n, B;
    cin >> n >> B;

    // p[i] 用来存数字 i 的最大质因子
    vector<int> p(n + 1, 0);

    // 筛法预处理
    for (int i = 2; i <= n; i++)
    {
        if (p[i] == 0)
        { // p[i] 还是 0，说明 i 是质数
            // 把 i 的所有倍数的最大质因子都更新为 i
            for (int j = i; j <= n; j += i)
            {
                p[j] = i;
            }
        }
    }

    // 统计答案
    int ans = 1; // 1 没有质因子，默认是 B-smooth 数，直接算上
    for (int i = 2; i <= n; i++)
    {
        if (p[i] <= B)
        {
            ans++;
        }
    }
    cout << ans << endl;
}

#ifndef LUOGU_MAIN
int main()
{
    B3969();
    return 0;
}
#endif