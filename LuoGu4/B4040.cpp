#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool isBW(vector<string> &ss)
{
    int n = ss.size();
    int m = ss[0].length();
    char pattern[4][4] = {
        {'0', '0', '0', '0'},
        {'0', '1', '1', '0'},
        {'0', '1', '1', '0'},
        {'0', '0', '0', '0'}};
    for (int i = 0; i + 3 < n; i++)
    {
        for (int j = 0; j + 3 < m; j++)
        {
            bool ok = true;
            for (int r = 0; r < 4; r++)
            {
                for (int c = 0; c < 4; c++)
                {
                    if (ss[i + r][j + c] != pattern[r][c])
                    {
                        ok = false;
                        break;
                    }
                }
                if (!ok)
                    break;
            }
            if (ok)
                return true; // 找到一个就返回
        }
    }
    return false;
}

void B4040()
{
    int t;
    cin >> t;
    vector<vector<string>> ss(t);
    for (int i = 0; i < t; i++)
    {
        int n, m;
        cin >> n >> m;
        vector<string> s(n);
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
        }
        ss[i] = s;
    }
    for (int i = 0; i < t; i++)
    {
        if (isBW(ss[i]))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}

#ifndef LUOGU_MAIN
int main()
{
    B4040();
    return 0;
}
#endif