#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_map>
using namespace std;

// 对 vector 的 [l, r] 区间升序排序
void sortRange(vector<int> &v, int l, int r)
{
    sort(v.begin() + l, v.begin() + r + 1);
}
void B4041()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        sortRange(nums, l - 1, r - 1);
    }
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
}

#ifndef LUOGU_MAIN
int main()
{
    B4041();
    return 0;
}
#endif