#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_map>
using namespace std;

void B4579()
{
    int n;
    cin >> n;

    if (n == 1)
    {
        cout << 2 << endl; // 1 个盘 A→B→C，2 步
        return;
    }

    vector<long long> f(n + 1), g(n + 1);
    f[1] = 1; // 1 个盘顺时针移 1 格：1 步
    g[1] = 2; // 1 个盘顺时针移 2 格：2 步

    for (int i = 2; i <= n; i++)
    {
        f[i] = 2 * g[i - 1] + 1;
        g[i] = 2 * g[i - 1] + f[i - 1] + 2;
    }

    cout << g[n] << endl;
}

#ifndef LUOGU_MAIN
int main()
{
    B4579();
    return 0;
}
#endif