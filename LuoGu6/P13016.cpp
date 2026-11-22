#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <numeric>
#include <stack>
using namespace std;

// 求质因数，从2开始枚举的第一个因数，他一定是质数。
int getParent(int x)
{
    if (x == 1)
    {
        return 1;
    }
    for (int i = 2; (long long)i * i <= x; i++)
    {
        if (x % i == 0)
        {
            return x / i;
        }
    }
    return 1;
}

//求两子节点x，y距离，可以通过将x，y中较深的往上跳，跳一次记录一次，知道两者相遇，此时的记录便是两者距离。
void P13016()
{
    int q;
    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        int dist = 0;
        while (x != y)
        {
            if (x > y)
            {
                x = getParent(x);
            }
            else
            {
                y = getParent(y);
            }
            dist++;
        }
        cout << dist << endl;
    }
}

#ifndef LUOGU_MAIN
int main()
{
    P13016();
    return 0;
}
#endif