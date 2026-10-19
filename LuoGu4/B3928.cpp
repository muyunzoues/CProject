#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_map>
using namespace std;

void B3927()
{
    int n;
    cin >> n;
    vector<int> u(n), v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> u[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(u.begin(), u.end());
    sort(v.begin(), v.end());
    int j = 0;
    int wins = 0;
    for (int i = 0; i < n; i++)
    {
        // 跳过所有赢不了 b[i] 的弱马
        while (j < n && u[j] <= v[i])
        {
            j++;
        }
        if (j < n)
        {
            wins++; // a[j] > b[i]，赢下这一场
            j++;    // 这匹强马用掉了
        }
    }

    cout << wins << endl;
}

#ifndef LUOGU_MAIN
int main()
{
    B3927();
    return 0;
}
#endif