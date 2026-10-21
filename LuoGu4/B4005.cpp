#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_map>
using namespace std;

void B4005()
{
    int n, m;
    cin >> n >> m;
    vector<string> ss(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ss[i];
    }
    vector<vector<int>> nums(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (ss[i][j] == '0')
            {
                nums[i][j] = -1;
            }
            else
            {
                nums[i][j] = 1;
            }
        }
    }
    int res = 0;
    for (int x1 = 0; x1 < n; x1++)
    {
        for (int x2 = x1; x2 < n; x2++)
        {
            for (int y1 = 0; y1 < m; y1++)
            {
                for (int y2 = y1; y2 < m; y2++)
                {
                    int sum = 0;
                    for (int i = x1; i <= x2; i++)
                    {
                        for (int j = y1; j <= y2; j++)
                        {
                            sum += nums[i][j];
                        }
                    }
                    if (sum == 0)
                    {
                        int area = (x2 - x1 + 1) * (y2 - y1 + 1);
                        res = max(res, area);
                    }
                }
            }
        }
    }
    cout << res << endl;
}

#ifndef LUOGU_MAIN
int main()
{
    B4005();
    return 0;
}
#endif