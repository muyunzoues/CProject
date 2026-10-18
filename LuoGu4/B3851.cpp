#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <cmath>
using namespace std;

// 十六进制字符转数值
int toNum(char c)
{
    if (c >= '0' && c <= '9')
        return c - '0';
    return c - 'A' + 10;
}

// 数值转两位十六进制字符串（用于色表输出）
string toHex2(int v)
{
    string res;
    res += (v / 16 <= 9) ? (v / 16 + '0') : (v / 16 - 10 + 'A');
    res += (v % 16 <= 9) ? (v % 16 + '0') : (v % 16 - 10 + 'A');
    return res;
}

// 数值转一位十六进制字符（用于图像输出）
char toHex1(int v)
{
    return (v <= 9) ? (v + '0') : (v - 10 + 'A');
}

// 按值排序：次数降序，次数相同灰度值升序
vector<pair<int, int>> sortByValue(const unordered_map<int, int> &scount)
{
    vector<pair<int, int>> v(scount.begin(), scount.end());
    sort(v.begin(), v.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         {
        if (a.second != b.second) return a.second > b.second;
        return a.first < b.first; });
    return v;
}

void B3851()
{
    int n;
    cin >> n;
    vector<string> rows(n);
    for (int i = 0; i < n; i++)
    {
        cin >> rows[i];
    }
    int m = rows[0].size() / 2;

    vector<vector<int>> a(n, vector<int>(m));
    unordered_map<int, int> scount;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int gray = toNum(rows[i][2 * j]) * 16 + toNum(rows[i][2 * j + 1]);
            a[i][j] = gray;
            scount[gray]++;
        }
    }

    // 第二步：按规则排序，取前 16 个
    auto sorted = sortByValue(scount);
    vector<int> top16;
    for (int i = 0; i < 16 && i < (int)sorted.size(); i++)
    {
        top16.push_back(sorted[i].first);
    }
    // 如果不足 16 种，补 0（题目通常保证足够，这里防御性处理）
    while (top16.size() < 16)
        top16.push_back(0);

    // 第三步：输出色表（每个灰阶两位十六进制）
    for (int i = 0; i < 16; i++)
    {
        cout << toHex2(top16[i]);
    }
    cout << endl;

    // 第四步：建立 0~255 到编号的映射
    int mp[256];
    for (int col = 0; col <= 255; col++)
    {
        int bestIdx = 0;
        int bestDiff = abs(col - top16[0]);
        for (int k = 1; k < 16; k++)
        {
            int diff = abs(col - top16[k]);
            if (diff < bestDiff)
            { // 严格小于，相等时保留编号小的
                bestDiff = diff;
                bestIdx = k;
            }
        }
        mp[col] = bestIdx;
    }

    // 第五步：输出压缩后的图像（每像素一位十六进制）
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << toHex1(mp[a[i][j]]);
        }
        cout << endl;
    }
}

#ifndef LUOGU_MAIN
int main()
{
    B3851();
    return 0;
}
#endif