#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;

bool check(const vector<long long> &a, long long x)
{
    vector<long long> b;
    for (long long i = 0; i < a.size(); i++)
    {
        if (a[i] > x)
        {
            b.push_back(a[i]);
        }
    }
    for (long long i = 0; i + 1 < b.size(); i += 2)
    {
        if (b[i] != b[i + 1])
        {
            return false;
        }
    }
    return true;
}

//二分答案，check函数检查是否可以将大于x的数两两配对,如果可以配对，则说明x是一个可行解，继续向左二分求最小解，否则向右二分求可行解
void P14917()
{
    long long n;
    cin >> n;
    vector<long long> a(n);
    long long m = LLONG_MIN;
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
        m = max(m, a[i]);
    }

    long long l = 0, r = m, res = m;
    while (l <= r)
    {
        long long mid = l + (r - l) / 2;
        if (check(a, mid))
        {
            res = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << res << endl;
}

#ifndef LUOGU_MAIN
int main()
{
    P14917();
    return 0;
}
#endif