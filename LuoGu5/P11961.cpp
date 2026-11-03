
#include <iostream>
#include <vector>
#define ll long long
using namespace std;
vector<ll> yin; // 表示p-1的因数
ll fpow(ll a, ll b, ll p)
{ // 快速幂
    a %= p;
    if (b == 1)
        return a;
    if (b == 0)
        return 1;
    if (b & 1)
        return a * fpow(a * a % p, (b >> 1), p) % p;
    return fpow(a * a % p, (b >> 1), p);
}
void find_yin(ll x)
{                      // 找因数
    while (yin.size()) // 清空
        yin.pop_back();
    for (ll i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            yin.push_back(i);
            yin.push_back(x / i);
        }
    }
    return;
}
void doing()
{ // 求出每次答案
    ll p, a;
    cin >> a >> p;
    if (fpow(a, p - 1, p) != 1)
    { // 条件2
        puts("No");
        return;
    }
    find_yin(p - 1); // 找p-1的因数
    for (int i = 0; i < yin.size(); i++)
    {
        ll y = yin[i]; // 枚举每个因数
        if (fpow(a, y, p) == 1)
        { // 满足条件4(不满足条件3)
            puts("No");
            return;
        }
    }
    puts("Yes");
    return;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        doing();
    }
    return 0;
}
