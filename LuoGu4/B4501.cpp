#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_map>
using namespace std;

void B4451()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> nums(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> nums[i][j];
        }
    }
    int res = 0;
    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}; // x偏移量
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1}; // y偏移量
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            bool flag = true;
            for (int k = 0; k < 8; k++) // 遍历八个方向
            {
                int x = i + dx[k];
                int y = j + dy[k];

                // 判断是否越界
                if (x >= 0 && x < n && y >= 0 && y < m) // 某个方向没有越界，则统计
                {
                    if (nums[i][j] > nums[x][y])
                    {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag)
            {
                res++;
            }
        }
    }
    cout << res << endl;
}

#ifndef LUOGU_MAIN
int main()
{
    B4451();
    return 0;
}
#endif