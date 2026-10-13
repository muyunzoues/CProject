#include<iostream>
#include<vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;

// 获取数字的每一位
vector<int> getDigits(int n) {
    vector<int> digits;
    if (n == 0) {
        digits.push_back(0);
    } else {
        while (n > 0) {
            digits.push_back(n % 10);
            n /= 10;
        }
        reverse(digits.begin(), digits.end());
    }
    return digits;
}


void B4067(){
    int n;
    cin>>n;
    string g[4][5] = {
    // 数字 0
    {".....", ".***.", ".***.", ".***.", "....."},
    // 数字 1
    {"****.", "****.", "****.", "****.", "****."},
    // 数字 2
    {".....", "****.", ".....", ".****", "....."},
    // 数字 3
    {".....", "****.", ".....", "****.", "....."}
};

    vector<int> digits = getDigits(n);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < digits.size(); j++) {
            cout << g[digits[j]][i];
        }
        cout << endl;
    }


}

#ifndef LUOGU_MAIN
int main()
{
    B4067();
    return 0;
}
#endif