#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

LL x;

int calc(int x)
{
    int res = 0, k = 1;
    while (x >= k)
    {
        res ++;
        x -= k ++;
    }
    return res;
}

int main()
{
    cin >> x;
    
    LL res = 0;
    for (int i = 2; i <= x / i; ++ i )
    {
        int cnt = 0;
        while (x % i == 0)
            x /= i, cnt ++;
        if (cnt)
            res += calc(cnt);
    }
    
    if (x > 1)
        res ++;
    
    cout << res << endl;
    
    return 0;
}
