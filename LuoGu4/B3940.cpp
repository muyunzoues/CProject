#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;

void B3940()
{
    int n;
    cin >> n;
    vector<vector<int>> nums(n, vector<int>(n, 0));
    int i = 0, j = n / 2;
    int count = 0;
    while (count < n * n)
    {
        count++;
        nums[i][j] = count;
        int ii = i, jj = j;
        if (i > 0)
        {
            i -= 1;
        }
        else if (i == 0)
        {
            i = n - 1;
        }
        if (j < n - 1)
        {
            j += 1;
        }
        else if (j == n - 1)
        {
            j = 0;
        }
        if (nums[i][j] == 0)
        {
            continue;
        }
        else
        {
            i = ii, j = jj;
            if (i < n - 1)
            {
                i += 1;
            }
            else if (i == n - 1)
            {
                i = 0;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
}

#ifndef LUOGU_MAIN
int main()
{
    B3940();
    return 0;
}
#endif