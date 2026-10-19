#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;

// 将十进制数转为二进制
string transTwo(long long n)
{
    if (n == 0)
        return "0"; // 特判 0
    string res;
    while (n > 0)
    {
        if (n & 1)
            res += '1';
        else
            res += '0'; // 取二进制最低位
        n >>= 1;        // 二进制右移一位
    }
    reverse(res.begin(), res.end());
    return res;
}
// 补零
vector<string> supplyZero(string ss)
{
    vector<string> res;
    int count = ss.length() / 7;
    if (ss.length() % 7 == 0)
    {
        int i = ss.length() - 1;
        int flag = 1;
        while (i >= 0)
        {
            if (flag == count)
            {
                res.push_back('0' + ss.substr(0, 7));
            }
            else
            {
                res.push_back('1' + ss.substr(i - 7 + 1, 7));
            }
            i -= 7;
            flag++;
        }
    }
    else
    {
        int i = ss.length() - 1;
        int flag = 1;
        while (i >= 6)
        {
            res.push_back('1' + ss.substr(i - 7 + 1, 7));
            i -= 7;
        }
        string temp = ss.substr(0, i + 1);
        while (temp.length() < 7)
        {
            temp = '0' + temp;
        }
        res.push_back('0' + temp);
    }
    return res;
}

// 把 8 位二进制字符串转成两位十六进制字符（大写）
string bin8ToHex(const string &bin)
{
    int val = 0;
    for (char c : bin)
    {
        val = val * 2 + (c - '0');
    }
    string hex;
    hex += (val / 16 <= 9) ? (val / 16 + '0') : (val / 16 - 10 + 'A');
    hex += (val % 16 <= 9) ? (val % 16 + '0') : (val % 16 - 10 + 'A');
    return hex;
}

void B3870()
{
    long long n;
    cin >> n;
    string ss = transTwo(n);
    vector<string> res = supplyZero(ss);
    for (int i = 0; i < (int)res.size(); i++)
    {
        if (i > 0)
            cout << " ";
        cout << bin8ToHex(res[i]);
    }
    cout << endl;
}

#ifndef LUOGU_MAIN
int main()
{
    B3870();
    return 0;
}
#endif