#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;


//先假设全部卖给B，得到总的res，然后计算每个C-B的差值，排序后取前n个最大的差值，加到res上，就能得到最终的最大值
void P11960()
{
    int n;
    cin >> n;
    vector<long long> numsb(2*n);
    vector<long long> numsc(2*n);
    vector<long long> nums(2*n);
    long long res=0;
    for (int i = 0; i < 2*n; i++)
    {
        cin >> numsb[i];
        res+=numsb[i];
    }
    for (int i = 0; i < 2*n; i++)
    {
        cin >> numsc[i];
        nums[i]=numsc[i]-numsb[i];
    }
    sort(nums.begin(),nums.end(),greater<long long>());
    for (int i = 0; i < n; i++){
        res+=nums[i];
    }
    cout << res << endl;
}

#ifndef LUOGU_MAIN
int main()
{
    P11960();
    return 0;
}
#endif