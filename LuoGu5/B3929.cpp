#include <iostream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;

bool isLucky[2000010];
vector<int> luck;

//判断是否完全平方数
inline bool iswp(int x)
{
    int k = sqrt(x);
    return k * k == x;
}

//找出大于x的最小幸运数
inline int find(int x)
{
    if (luck[0] > x)
        return luck[0];
    int l = 0, r = luck.size() - 1;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (luck[mid] > x && luck[mid - 1] < x)
        {
            return luck[mid];
        }
        if (luck[mid] < x)
        {
            l = mid + 1;
        }
        if (luck[mid - 1] > x)
        {
            r = mid - 1;
        }
    }
    return -1;
}

void B3929()
{
    int a, N;
    cin >> a >> N;
    for (int i = a; i < 2000010; i++)
    {
        if (iswp(i))
        {
            for (int j = i; j < 2000010; j += i)
            {
                isLucky[j] = true;
                luck.push_back(j);
            }
        }
    }
    sort(luck.begin(), luck.end());
    while (N--)
    {
        int x;
        cin >> x;
        if (isLucky[x])
        {
            cout << "lucky" << endl;
        }
        else
        {
            cout << find(x) << endl;
        }
    }
}

#ifndef LUOGU_MAIN
int main()
{
    B3929();
    return 0;
}
#endif