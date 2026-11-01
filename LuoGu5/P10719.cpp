#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_map>
using namespace std;

void P10719()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> ss(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char s;
            cin >> s;
            if (s - '0' > 0)
            {
                ss[i][j]++;
            }
            ss[i][j] = ss[i][j] + ss[i - 1][j] + ss[i][j - 1] - ss[i - 1][j - 1];
        }
    }
    int res = INT_MAX;
    for (int x1 = 1; x1 <= n; x1++)
    {
        for (int y1 = 1; y1 <= m; y1++)
        {
            for (int x2 = x1; x2 <= n; x2++)
            {
                for (int y2 = y1; y2 <= m; y2++)
                {
                    int cnt = ss[x2][y2] - ss[x1 - 1][y2] - ss[x2][y1 - 1] + ss[x1 - 1][y1 - 1];
                    if (cnt >= k)
                    {
                        res = min(res, (x2 - x1 + 1) * (y2 - y1 + 1));
                    }
                }
            }
        }
    }
    if (res == INT_MAX)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << res << endl;
    }
}

#ifndef LUOGU_MAIN
int main()
{
    P10719();
    return 0;
}
#endif