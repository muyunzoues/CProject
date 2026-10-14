#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;
void B4450()
{
    int m, n;
    cin >> m >> n;
    // vector<vector<int>> nums(n,vector<int>(2));
    vector<int> temp(m,INT_MAX);
    for (int i = 0; i < n; i++)
    {
        int x,y;
        cin>>x>>y;
        if(y<temp[x-1]){
            temp[x-1]=y;
        }
    }
    int res=0;
    for (int i = 0; i < m; i++)
    {
        res+=temp[i];
    }
    cout<<res<<endl;

}

#ifndef LUOGU_MAIN
int main()
{
    B4450();
    return 0;
}
#endif