#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;
// 得到数字n的二进制串
string getTwo(int n)
{
    string res;
    while (n > 0)
    {
        int temp = n & 1;
        n >>= 1;
        res += to_string(temp);
    }
    reverse(res.begin(), res.end());
    return res;
}
// 判断二进制串是否回文
bool isTrace(string ss)
{
    int i = 0, j = ss.length() - 1;
    while (i < j)
    {
        if (ss[i] != ss[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}
void B4499()
{
    int n;
    cin >> n;
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (isTrace(getTwo(i)))
        {
            res++;
        }
    }
    cout << res << endl;
}

#ifndef LUOGU_MAIN
int main()
{
    B4499();
    return 0;
}
#endif