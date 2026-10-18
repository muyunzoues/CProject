#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;

// 获取n的k次方
long long getNK(long long n, int k)
{
    long long res = 1;
    for (int i = 0; i < k; i++)
    {
        res *= n;
    }
    return res;
}

// 获取k进制数n转化为的十进制数
long long transK(int k, string s)
{
    long long res = 0;
    int count = 0;
    int n = s.length();
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            res += (long long)(s[i] - '0') * getNK(k, count);
        }
        else if (s[i] >= 'A' && s[i] <= 'F')
        {
            res += (long long)(s[i] - 'A' + 10) * getNK(k, count);
        }
        count++;
    }
    return res;
}

void B3869()
{
    int n;
    cin >> n;
    vector<int> numsK(n);
    vector<string> ss(n);
    for (int i = 0; i < n; i++)
    {
        cin >> numsK[i] >> ss[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << transK(numsK[i], ss[i]) << endl;
    }
}

#ifndef LUOGU_MAIN
int main()
{
    B3869();
    return 0;
}
#endif