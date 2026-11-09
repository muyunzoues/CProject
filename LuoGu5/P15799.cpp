#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

const int MAXA = 100000;

void P14918()
{
    int n, m;
    cin >> n >> m;
    unordered_map<int, int> ans;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        ans[num]++;
    }
    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;
        ans[num]++;
    }
    int count = 0;
    for (const auto &pair : ans)
    {
        if (pair.second == 2)
        {
            count++;
        }
    }
    cout << count << endl;
}

#ifndef LUOGU_MAIN
int main()
{
    P14918();
    return 0;
}
#endif