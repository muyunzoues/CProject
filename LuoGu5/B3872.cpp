#include <iostream>
using namespace std;

void B3871()
{
    long long n;
    cin >> n;

    bool first = true; // 是否是第一个输出的质因数

    // 试除到 sqrt(n)
    for (long long i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            int cnt = 0;
            while (n % i == 0)
            {
                n /= i;
                cnt++;
            }
            if (!first)
                cout << " * ";
            if (cnt == 1)
                cout << i;
            else
                cout << i << "^" << cnt;
            first = false;
        }
    }

    // 剩余部分本身是质数
    if (n > 1)
    {
        if (!first)
            cout << " * ";
        cout << n;
    }
    cout << endl;
}

#ifndef LUOGU_MAIN
int main()
{
    B3871();
    return 0;
}
#endif