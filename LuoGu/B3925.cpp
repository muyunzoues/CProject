#include<iostream>
#include<vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;



void B3925(){
    int n, i;
    cin >> n >> i;

    // 特例：只有 1 只猫
    if (n == 1) {
        cout << 1 << endl;
    }

    // 从小到大枚举最后一只猫拿走的鱼数 last
    for (int last = 1; ; last++) {
        long long cur = (long long)last * n + i;  // 最后一只猫分鱼前的鱼数
        bool ok = true;

        // 逆推 n-1 次，回到最初状态
        for (int k = 1; k < n; k++) {
            if (cur % (n - 1) != 0) {  // 必须能整除，否则这个 last 不成立
                ok = false;
                break;
            }
            cur = cur / (n - 1) * n + i;  // 逆推公式
        }

        if (ok) {
            cout << cur << endl;
            break;
        }
    }

}

#ifndef LUOGU_MAIN
int main()
{
    B3925();
    return 0;
}
#endif