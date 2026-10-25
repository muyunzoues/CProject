#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct Commodity
{
    string name;
    int price;
    int v;
};

//a是否应排在b前面
bool cmp(const Commodity &a, const Commodity &b)
{
    if (a.v != b.v)
        return a.v < b.v; // 优先级不同，直接比优先级
    if (a.price != b.price)
        return a.price < b.price; // 优先级相同，比价格
    return a.name < b.name;       // 都相同，比名字
}

void B4451()
{
    int m, n;
    cin >> m >> n;
    vector<Commodity> commos(n);
    for (int i = 0; i < n; i++)
    {
        Commodity c;
        cin >> c.name >> c.price >> c.v;
        commos[i] = c;
    }
    sort(commos.begin(), commos.end(), cmp);//传入比较规则
    vector<string> res;
    for (int i = 0; i < n; i++)
    {
        if (m >= commos[i].price)
        {
            m -= commos[i].price;
            res.push_back(commos[i].name);
        }
    }
    sort(res.begin(), res.end());
    for (string r : res)
    {
        cout << r << endl;
    }
}

#ifndef LUOGU_MAIN
int main()
{
    B4451();
    return 0;
}
#endif