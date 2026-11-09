#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

const int MAXA = 100000;

void P17010()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end(), greater<int>());
    int ans = nums[0];
    for (int i = 1; i < n; i++)
    {
        nums[i] += nums[i - 1];
        ans+= nums[i];
    }
    cout << ans << endl;
}

#ifndef LUOGU_MAIN
int main()
{
    P17010();
    return 0;
}
#endif