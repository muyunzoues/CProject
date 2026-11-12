#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <numeric>
using namespace std;

int n;
int a[10], b[10];
bool vis[10];
int ans = INT_MAX;

void dfs(int step, int pre, int len)
{
    if(step == n)
    {
        ans = min(ans, len);
        return;
    }
    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            vis[i] = true;
            int add;
            if(pre == 0)
                add = 1;
            else
                add = max(a[i], b[pre]) + 1;
            dfs(step + 1, i, len + add);
            vis[i] = false;
        }
    }
}

void P10377()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        cin >> b[i];
    dfs(0, 0, 0);
    cout << ans << endl;
}

#ifndef LUOGU_MAIN
int main()
{
    P10377();
    return 0;
}
#endif