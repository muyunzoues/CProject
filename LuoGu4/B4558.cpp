#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_map>
using namespace std;

// 保留元素的序号进行排序，可以采用结构体存储的方式
struct Node
{
    double val;
    int id; // 原始编号
};
bool cmp(const Node &a, const Node &b)
{
    if (a.val != b.val)
        return a.val > b.val; // 按值由高到低排序
    return a.id < b.id;
}

void B4557()
{
    int n;
    cin >> n;
    vector<int> w(n);
    vector<double> h(n);
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    vector<Node> res(n);
    for (int i = 0; i < n; i++)
    {
        res[i].val = w[i] / h[i] / h[i];
        res[i].id = i + 1;
    }
    sort(res.begin(), res.end(), cmp);
    for (int i = 0; i < n; i++)
    {
        cout << res[i].id << " ";
    }
}

#ifndef LUOGU_MAIN
int main()
{
    B4557();
    return 0;
}
#endif