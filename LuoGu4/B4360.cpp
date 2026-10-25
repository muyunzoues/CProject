#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

void B4360()
{
    int n, m;
    cin >> n >> m;
    int x1, x2, y1, y2;
    cin >> x1 >> x2 >> y1 >> y2;
    vector<string> ss(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ss[i];
    }
    for (int i = x1 - 1; i < x2; i++)
    {
        string temp;
        for (int j = y1 - 1; j < y2; j++)
        {
            temp += ss[i][j];
        }
        cout << temp << endl;
    }
}

#ifndef LUOGU_MAIN
int main()
{
    B4360();
    return 0;
}
#endif