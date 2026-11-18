#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <numeric>
#include <stack>
using namespace std;

void P11963()
{
    int n;
    cin >> n;
    vector<long long> nums(n);
    long long total = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        total += nums[i];
    }
    vector<long long> dpMax(n), dpMin(n);
    dpMax[0] = nums[0];
    dpMin[0] = nums[0];
    long long maxSum = nums[0], minSum = nums[0];
    for (int i = 1; i < n; i++)
    {
        dpMax[i]=max(nums[i],dpMax[i-1]+nums[i]);
        dpMin[i]=min(nums[i],dpMin[i-1]+nums[i]);
        maxSum=max(maxSum,dpMax[i]);
        minSum=min(minSum,dpMin[i]);
    }
    long long res;
    if(maxSum<0){
        res=maxSum;
    }
    else{
        res=max(maxSum,maxminSumSum-);
    }
}

#ifndef LUOGU_MAIN
int main()
{
    P11963();
    return 0;
}
#endif