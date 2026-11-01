#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;

set<int> getYin(int n)
{
    set<int> res;
    for (int i = 2; i * i <= n; i++)
    { // 注意 <=
        while (n % i == 0)
        {
            res.insert(i);
            n /= i;
        }
    }
    if (n > 1)
    { // 处理剩余的大质因子
        res.insert(n);
    }
    return res;
}
void P10720()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (getYin(nums[i]).size() == 2)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
}

#ifndef LUOGU_MAIN
int main()
{
    P10720();
    return 0;
}
#endif