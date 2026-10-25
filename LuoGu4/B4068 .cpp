#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool getNum(vector<int> &nums, int num)
{
    for (int n : nums)
    {
        if (n == num)
        {
            return false;
        }
    }
    return true;
}

void B4068()
{
    int n;
    cin >> n;
    vector<int> nums(n + 1);
    nums[1] = 1;
    for (int i = 2; i < n + 1; i++)
    {
        if (nums[i - 1] - i > 0 && !getNum(nums, nums[i - 1] - i))
        {
            nums[i] = nums[i - 1] - i;
        }
        else
        {
            nums[i] = nums[i - 1] + i;
        }
    }
    sort(nums.begin() + 1, nums.end());
    for (int i = 1; i < n + 1; i++)
    {
        cout << nums[i] << " ";
    }
}

#ifndef LUOGU_MAIN
int main()
{
    B4068();
    return 0;
}
#endif