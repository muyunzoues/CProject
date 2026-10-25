#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_map>
using namespace std;

void B4416()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    int res = 0;
    int i = 0;
    while (i < n)
    {
        int j = i;
        int count = 1;
        while (j + 1 < n)
        {
            if (nums[j + 1] == nums[j])
            {
                j++; // 重复元素，跳过，count 不变
            }
            else if (nums[j + 1] == nums[j] + 1)
            {
                j++; // 连续，count 加 1
                count++;
            }
            else
            {
                break; // 既不重复也不连续，停止
            }
        }
        i=j+1;
        res = max(res, count);
    }
    cout << res << endl;
}

#ifndef LUOGU_MAIN
int main()
{
    B4416();
    return 0;
}
#endif