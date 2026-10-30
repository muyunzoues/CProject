#include <iostream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;

//贪心的思想，按照R降序，从前往后遍历当前最大的R，从截止时间开始向前寻找第一个空闲的时间段进行安排
struct game
{
    int T;
    int R;
};

bool cmp(const game &a, const game &b)
{
    return a.R > b.R;
}
void B3872()
{
    int n;
    cin >> n;
    vector<game> games(n);
    vector<bool> flag(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> games[i].T;
        flag[i] = false;
    }
    flag[n] = false;
    for (int i = 0; i < n; i++)
    {
        cin >> games[i].R;
    }

    sort(games.begin(), games.end(), cmp);
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = games[i].T; j > 0; j--)
        {
            if (!flag[j])
            {
                flag[j] = true;
                res += games[i].R;
                break;
            }
        }
    }
    cout << res << endl;
}

#ifndef LUOGU_MAIN
int main()
{
    B3872();
    return 0;
}
#endif