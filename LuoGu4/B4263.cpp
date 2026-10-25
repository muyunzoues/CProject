#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

// 判断位置 (x, y) 在“忽略 (ox, oy) 处的障碍物”的前提下，是不是好格子
// 如果 (x,y) 不是 '.' 直接返回 false
// ignoreX/ignoreY 表示把该位置的 '#' 临时当作 '.'
bool isGood(const vector<string> &g, int x, int y, int ignoreX, int ignoreY)
{
    int n = g.size(), m = g[0].size();
    // 当前格子的实际字符（如果就是被忽略的障碍物，视为 '.'）
    char cur = g[x][y];
    if (x == ignoreX && y == ignoreY)
        cur = '.';
    if (cur != '.')
        return false;

    // 检查四个邻居，若邻居是被忽略的障碍物，也视为 '.'
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    for (int k = 0; k < 4; k++)
    {
        int nx = x + dx[k], ny = y + dy[k];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            continue;
        char nc = g[nx][ny];
        if (nx == ignoreX && ny == ignoreY)
            nc = '.';
        if (nc == '#')
            return false;
    }
    return true;
}

void B4263()
{
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for (int i = 0; i < n; i++)
        cin >> g[i];

    // 1. 初始好格子总数（不忽略任何障碍物）
    int base = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (isGood(g, i, j, -1, -1))
                base++;

    int ans = base;

    // 2. 对每个障碍物，只计算它自己和四个邻居的变化
    int dx[5] = {0, -1, 1, 0, 0};
    int dy[5] = {0, 0, 0, -1, 1};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (g[i][j] != '#')
                continue;

            int delta = 0;
            // 只检查 (i,j) 和四个邻居
            for (int k = 0; k < 5; k++)
            {
                int x = i + dx[k], y = j + dy[k];
                if (x < 0 || x >= n || y < 0 || y >= m)
                    continue;

                bool before = isGood(g, x, y, -1, -1); // 移除前
                bool after = isGood(g, x, y, i, j);    // 移除后（把 (i,j) 当 '.'）
                if (after && !before)
                    delta++;
                else if (!after && before)
                    delta--;
            }
            ans = max(ans, base + delta);
        }
    }

    cout << ans << endl;
}

#ifndef LUOGU_MAIN
int main()
{
    B4263();
    return 0;
}
#endif