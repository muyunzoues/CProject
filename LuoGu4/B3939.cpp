#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;
// 获取数字分割后的集合
vector<int> getNums(int num)
{
    vector<int> res;
    while (num > 0)
    {
        int temp = num % 10;
        if (temp > 0)
        {
            res.push_back(temp);
        }
        num /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}
// 获取10的n次方
long long power10(int n)
{
    long long res = 1;
    for (int i = 0; i < n; i++)
    {
        res *= 10;
    }
    return res;
}
// 获取倒转后的数
int getNumsSum(vector<int> &nums)
{
    int res = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int temp = power10(i);
        res += nums[i] * temp;
    }
    return res;
}
// 判断是否是绝对素数
bool isAbSuNum(int num)
{
    vector<int> nums = getNums(num);
    int SuNum = getNumsSum(nums);
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
            return false;
    }
    for (int i = 2; i * i <= SuNum; i++)
    {
        if (SuNum % i == 0)
            return false;
    }
    return true;
}

void B3939()
{
    int a, b;
    cin >> a >> b;
    for (int i = a; i <= b; i++)
    {
        if (isAbSuNum(i))
        {
            cout << i << endl;
        }
    }
}

#ifndef LUOGU_MAIN
int main()
{
    B3939();
    return 0;
}
#endif