#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_map>
using namespace std;

void B4415()
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
    for (int x1 = 0; x1 < n; x1++)
    {
        for (int y1 = 0; y1 < m; y1++)
        {
            for (int x2 = x1; x2 < n; x2++)
            {
                for (int y2 = y1; y2 < m; y2++)
                {
                    bool flag = true;
                    for (int i = x1; i <= x2; i++)
                    {
                        for (int j = y1; j <= y2; j++)
                        {
                            if (nums[i][j] != 1)
                            {
                                flag = false;
                                break;
                            }
                        }
                        if (!flag)
                        {
                            break;
                        }
                    }
                    if (flag)
                    {
                        int s=(x2-x1+1)*(y2-y1+1);
                        res = max(res,s);
                    }
                }
            }
        }
    }
    cout<<res<<endl;
}

#ifndef LUOGU_MAIN
int main()
{
    B4415();
    return 0;
}
#endif