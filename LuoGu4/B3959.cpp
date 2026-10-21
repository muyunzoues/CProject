#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_map>
using namespace std;

void B3959()
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
    int day = 1;
    while (i < nums.size())
    {
        while (nums[i] >= day)
        {
            i++;
            res++;
            day++;
        }
        i++;
    }
    cout << res << endl;
}

#ifndef LUOGU_MAIN
int main()
{
    B3959();
    return 0;
}
#endif