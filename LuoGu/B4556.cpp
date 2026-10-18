#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

void B4556()
{
    int n;
    cin >> n;
    string ss;
    cin >> ss;
    for (int i = 0; i < ss.length(); i++)
    {
        if (ss[i] >= '0' && ss[i] <= '9')
        {
            ss[i] = '*';
        }
        else if (ss[i] >= 'A' && ss[i] <= 'Z')
        {
            ss[i] = ss[i] - 'A' + 'a';
        }
        else
        {
            ss[i] = ss[i] - 'a' + 'A';
        }
    }
    cout << ss << endl;
}

#ifndef LUOGU_MAIN
int main()
{
    B4556();
    return 0;
}
#endif