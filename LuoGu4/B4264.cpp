#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

void B4264()
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
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i + 1 < n && j + 1 < m && nums[i][j] * nums[i + 1][j + 1] == nums[i + 1][j] * nums[i][j + 1])
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
    B4264();
    return 0;
}
#endif