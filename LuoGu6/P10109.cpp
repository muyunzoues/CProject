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
vector<int> parent_node(305);

// 判断 x 是否能管理 y
bool canManage(int x, int y)
{
    if (x == y)
        return true;
    if (y == 0)
        return false;
    return canManage(x, parent_node[y]);
}

void P10108()
{
    int n;
    cin >> n;
    parent_node[0] = 0;
    for (int i = 1; i < n; i++)
    {
        cin >> parent_node[i];
    }
    int q;
    cin >> q;
    while (q--)
    {
        int m;
        cin >> m;
        vector<int> participants(m);
        for (int i = 0; i < m; i++)
        {
            cin >> participants[i];
        }
        // 从后往前遍历，找到编号最大的员工，看他是否能管理所有参会人员
        for (int i = n - 1; i >= 0; i--)
        {
            bool flag = true;
            for (int j = 0; j < m; j++)
            {
                if (!canManage(i, participants[j]))
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                cout << i << endl;
                break;
            }
        }
    }
}

#ifndef LUOGU_MAIN
int main()
{
    P10108();
    return 0;
}
#endif