#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_map>
using namespace std;

void B4006()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    int res=0;
    //将i视为最大的数，便利i左边的数，直至nums[i]-nums[j]>k
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j >= 0; j--)
        {
            if (nums[i]-nums[j]<=k){
                sum+=nums[j];
            }
        }
        res = max(res, sum);
    }
    cout<<res<<endl;
}

#ifndef LUOGU_MAIN
int main()
{
    B4006();
    return 0;
}
#endif