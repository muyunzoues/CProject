#include<iostream>
#include<vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;


void B3923(){
    int a, b, m, n;
cin >> a >> b >> m >> n;

long long sum = a + b;  // 总和，注意用 long long 防溢出

if (a >= m) { cout << a; return; }
if (b >= m) { cout << a + b; return; }

for (int i = 3; i <= n; i++) {
    int day = a + b;
    sum += day;
    if (day >= m) break;
    a = b;
    b = day;
}
cout << sum;
}

#ifndef LUOGU_MAIN
int main()
{
    B3923();
    return 0;
}
#endif