#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;
// 获取分割后的集合
vector<int> getNums(int num)
{
    vector<int> res;
    while (num > 0)
    {
        res.push_back(num % 10); // 不管是不是 0 都保留
        num /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

bool isLuckyNum(long long num)
{
    int sum = 0;
    int pos = 1; // 当前位数，从个位（第 1 位）开始
    while (num > 0)
    {
        int digit = num % 10;
        if (pos % 2 == 1)
        { // 奇数位
            int t = digit * 7;
            while (t > 9)
            {
                t = t / 10 + t % 10;
            }
            sum += t;
        }
        else
        { // 偶数位不变
            sum += digit;
        }
        num /= 10;
        pos++;
    }
    return sum % 8 == 0;
}

void B3850() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        cout << (isLuckyNum(x) ? "T" : "F") << endl;
    }
}

#ifndef LUOGU_MAIN
int main()
{
    B3850();
    return 0;
}
#endif