#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;

void B3951()
{
    int n;
    cin >> n;
    vector<int> height(n);
    for (int i = 0; i < n; i++)
        cin >> height[i];

    int m;
    cin >> m;
    set<int> currentHeights; // 记录当前队伍中不同身高

    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        int h = height[x];

        // 统计严格大于 h 的不同身高个数
        int cnt = 0;
        for (int v : currentHeights)
        {
            if (v > h)
                cnt++;
        }
        cout << cnt << endl;

        currentHeights.insert(h);
    }
}

#ifndef LUOGU_MAIN
int main()
{
    B3951();
    return 0;
}
#endif