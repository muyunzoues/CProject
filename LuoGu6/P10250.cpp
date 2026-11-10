#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <numeric>
using namespace std;



void P10250()
{
    int n;
    cin >> n;
    vector<long long> nums(65);
    nums[0] = 1;
    nums[1] = 1;
    nums[2] = 2;
    for(int i = 3; i <= n; i++)
    {
        nums[i] = nums[i - 1] + nums[i - 2]+ nums[i - 3];
    }
    cout<<nums[n]<<endl;
}

#ifndef LUOGU_MAIN
int main()
{
    P10250();
    return 0;
}
#endif