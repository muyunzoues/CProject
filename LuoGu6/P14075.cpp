#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <numeric>
#include <stack>
using namespace std;

void P14075()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;
    vector<long long> score(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> score[i];
    }
    vector<long long> dp(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        bool vis[26] = {false};
        for (int j = i; j >= 1 && j >= i - 25; j--)
        {
            int temp = s[j] - 'a';
            if (vis[temp])
            {
                break;
            }
            vis[temp] = true;
            int len = i - j + 1;
            dp[i] = max(dp[i], dp[j - 1] + score[len]);
        }
    }
    cout << dp[n] << endl;
}

#ifndef LUOGU_MAIN
int main()
{
    P14075();
    return 0;
}
#endif