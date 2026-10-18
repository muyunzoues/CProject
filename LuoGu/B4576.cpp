#include<iostream>
#include<vector>
#include <iomanip>
#include <cmath>
#include <climits>
using namespace std;


void B4576(){
    int a, b, c;
cin >> a >> b >> c;
int cnt = 1;

for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 16; j++) {
        if (cnt == a) cout << (char)a;
        else if (cnt == b) cout << (char)b;
        else if (cnt == c) cout << (char)c;
        else cout << '*';
        cnt++;
    }
    cout << endl;
}
}

#ifndef LUOGU_MAIN
int main()
{
    B4576();
    return 0;
}
#endif