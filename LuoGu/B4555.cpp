#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

void B4555()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    vector<int> pnums(10);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    for (int i = 0; i < 10; i++)
    {
        cin >> pnums[i];
    }
    for (int i = 0; i < n; i++)
    {
        nums[i] = pnums[nums[i]];
    }
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
}

#ifndef LUOGU_MAIN
int main()
{
    B4555();
    return 0;
}
#endif