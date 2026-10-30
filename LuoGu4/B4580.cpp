#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_map>
using namespace std;

void B4580()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> nums(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        vector<int> temp(m);
        for (int j = 0; j < m; j++)
        {
            cin>>temp[j];
        }
        sort(temp.begin(),temp.end());
        nums[i]=temp;
    }
    for (int j = 0; j < m; j++)
    {
        vector<int> temp(n);
        for (int i = 0; i < n; i++)
        {
            temp[i]=nums[i][j];
        }
        sort(temp.begin(),temp.end());
        for (int i = 0; i < n; i++)
        {
            nums[i][j]=temp[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout<<nums[i][j]<<" ";
        }
        cout<<endl;
    }
}

#ifndef LUOGU_MAIN
int main()
{
    B4580();
    return 0;
}
#endif