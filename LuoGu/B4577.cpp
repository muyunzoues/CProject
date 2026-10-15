#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

vector<int> getTwoInt(int n)
{
    vector<int> res;
    while (n > 0)
    {
        int temp = n & 1;
        n >>= 1;
        res.push_back(temp);
    }
    return res;
}

void B4577()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int res = 0;
    vector<vector<int>> temp(n);
    int mSize = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        temp[i] = getTwoInt(nums[i]);
        mSize = min(mSize, (int)temp[i].size());
    }

    for (int i = 0; i < mSize; i++)
    {
        bool flag = true;
        for (int j = 0; j < n; j++)
        {
            if (temp[j][i] != 1)
            {
                flag = false;
                break;
            }
        }
        if (flag)
            res++;
    }
    cout << res << endl;
}

#ifndef LUOGU_MAIN
int main()
{
    B4577();
    return 0;
}
#endif