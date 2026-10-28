#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Array
{
private:
    vector<int> nums; // 存储元素
    int number;       // 编号

public:
    // 构造函数：初始化数组
    Array(const vector<int> &arr, int n)
    {
        nums = arr;
        number = n;
    }

    int getNumber() const
    {
        return number;
    }

    // 求数组元素之和
    int sum() const
    {
        int result = 0;
        for (int x : nums)
        {
            result += x;
        }
        return result;
    }

    // 求数组最大值
    int maxValue() const
    {
        if (nums.empty())
        {
            throw runtime_error("数组为空，无法求最大值");
        }
        return *max_element(nums.begin(), nums.end());
    }

    // 求数组最小值
    int minValue() const
    {
        if (nums.empty())
        {
            throw runtime_error("数组为空，无法求最小值");
        }
        return *min_element(nums.begin(), nums.end());
    }
};

// a是否应排在b前面
bool cmp(const Array &a, const Array &b)
{
    if (a.sum() != b.sum())
        return a.sum() < b.sum();
    if (a.maxValue() != b.maxValue())
        return a.maxValue() < b.maxValue();
    if (a.minValue() != b.minValue())
        return a.minValue() < b.minValue();
    return a.getNumber() < b.getNumber();
}

void B4502()
{
    int n, k;
    cin >> n >> k;
    vector<Array> array;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp(k);
        for (int j = 0; j < k; j++)
        {
            cin >> temp[j];
        }
        array.push_back(Array(temp, i));
    }
    sort(array.begin(), array.end(), cmp);
    for (int i = 0; i < n; i++)
    {
        cout << array[i].getNumber() + 1 << " ";
    }
}

#ifndef LUOGU_MAIN
int main()
{
    B4502();
    return 0;
}
#endif