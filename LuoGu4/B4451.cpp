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
    int m, n, h;
    cin >> m >> n >> h;
    vector<vector<int>> nums(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> nums[i][j];
        }
    }
    int res = 0;
    for (int x1 = 0; x1 + 2 < m; x1++)
    {
        for (int y1 = 0; y1 + 2 < n; y1++)
        {
            int ma = INT_MIN, mi = INT_MAX;
            int sum = 0;
            for (int i = x1; i <= x1 + 2; i++)
            {
                for (int j = y1; j <= y1 + 2; j++)
                {
                    ma = max(ma, nums[i][j]);
                    mi = min(mi, nums[i][j]);
                    sum += nums[i][j];
                }
            }
            if (ma - mi > h)
            {
                continue;
            }
            else
            {
                res = max(res, sum);
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