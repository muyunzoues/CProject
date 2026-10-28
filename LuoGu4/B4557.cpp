#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_map>
using namespace std;

void B4557()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> nums(q, vector<int>(2));
    vector<vector<string>> map(n, vector<string>(m));
    for (int i = 0; i < q; i++)
    {
        vector<int> temp(2);
        for (int j = 0; j < 2; j++)
        {
            cin >> temp[j];
        }
        map[temp[0] - 1][temp[1] - 1] = "*";
        nums[i] = temp;
    }

    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}; // x偏移量
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1}; // y偏移量
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] != "*")
            {
                int count = 0;
                for (int k = 0; k < 8; k++) // 遍历八个方向
                {
                    int x = i + dx[k];
                    int y = j + dy[k];

                    // 判断是否越界
                    if (x >= 0 && x < n && y >= 0 && y < m) // 某个方向没有越界，则统计
                    {
                        if (map[x][y] == "*")
                        {
                            count++;
                        }
                    }
                }
                map[i][j]='0'+count;
            }
            cout<<map[i][j]<<" ";
        }
        cout<<endl;
    }
}

#ifndef LUOGU_MAIN
int main()
{
    B4557();
    return 0;
}
#endif