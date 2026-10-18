#include<iostream>
#include<vector>
#include <iomanip>
#include <cmath>
#include <climits>
using namespace std;


void B4554(){
    int n;
cin >> n;
int center = n;  // 中心行列号

for (int i = 1; i <= 2 * n - 1; i++) {
    for (int j = 1; j <= 2 * n - 1; j++) {
        if (abs(i - center) + abs(j - center) == n - 1) {
            cout << '+';
        } else {
            cout << '.';
        }
    }
    cout << endl;  // 每行结束换行
}
}

#ifndef LUOGU_MAIN
int main()
{
    B4554();
    return 0;
}
#endif