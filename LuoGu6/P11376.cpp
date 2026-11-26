#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct sta
{
    int p, c;
};
struct car
{
    int a, b;
};

bool cmpSta(const sta &s1, const sta &s2) { return s1.p < s2.p; }

// 组 F：a >= b，按 a-b 降序
bool cmpF(const car &c1, const car &c2)
{
    return (long long)c1.a - c1.b > (long long)c2.a - c2.b;
}
// 组 G：a < b，按 b-a 降序（即 a-b 升序）
bool cmpG(const car &c1, const car &c2)
{
    return (long long)c1.b - c1.a > (long long)c2.b - c2.a;
}

void P11376()
{
    int n, m, x;
    cin >> n >> m >> x;
    vector<sta> stas(n);
    vector<car> carsF, carsG;
    for (int i = 0; i < n; i++)
        cin >> stas[i].p >> stas[i].c;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a >= b)
            carsF.push_back({a, b});
        else
            carsG.push_back({a, b});
    }

    sort(stas.begin(), stas.end(), cmpSta);
    sort(carsF.begin(), carsF.end(), cmpF);
    sort(carsG.begin(), carsG.end(), cmpG);

    long long res = 0;
    int l = 0, r = n - 1;

    // 组 F：从左往右分配
    for (auto &c : carsF)
    {
        while (l < n && stas[l].c == 0)
            l++;
        stas[l].c--;
        long long p = stas[l].p;
        res += 2LL * c.a * p + 2LL * c.b * (x - p);
    }

    // 组 G：从右往左分配
    for (auto &c : carsG)
    {
        while (r >= 0 && stas[r].c == 0)
            r--;
        stas[r].c--;
        long long p = stas[r].p;
        res += 2LL * c.a * p + 2LL * c.b * (x - p);
    }

    cout << res << endl;
}

#ifndef LUOGU_MAIN
int main()
{
    P11376();
    return 0;
}
#endif