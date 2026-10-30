#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_map>
using namespace std;

long long gcd(long long a, long long b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

void B3941()
{
    int n;
    cin >> n;
    vector<long long> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    long long ans = nums[0];
    for (int i = 1; i < n; i++)
    {
        ans = ans / gcd(ans, nums[i]) * nums[i]; // 先除后乘，防溢出
    }
    cout << ans << endl;
}

#ifndef LUOGU_MAIN
int main()
{
    B3941();
    return 0;
}
#endif