#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

void B4500()
{
    string ss1, ss2, ss3;
    cin >> ss1 >> ss2 >> ss3;
    int dis = ss2[0] - ss1[0];
    for (int i = 0; i < ss3.length(); i++)
    {
        if (ss3[i] >= 'A' && ss3[i] <= 'Z')
        {
            int offset = ss3[i] - 'A';
            offset = ((offset - dis) % 26 + 26) % 26; // 循环位移
            ss3[i] = 'A' + offset;
        }
    }
    cout << ss3 << endl;
}

#ifndef LUOGU_MAIN
int main()
{
    B4500();
    return 0;
}
#endif