#include<iostream>
#include<vector>
#include <iomanip>
#include <cmath>
#include <climits>
using namespace std;
void B4412(){
    int n;
    cin >> n;
    int mid = (n + 1) / 2;
    for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
        if (abs(i - mid) + abs(j - mid) == mid - 1) {
            cout << '#';
        } else {
            cout << '.';
        }
    }
    cout << endl;
}
}

#ifndef LUOGU_MAIN
int main()
{
    B4412();
    return 0;
}
#endif