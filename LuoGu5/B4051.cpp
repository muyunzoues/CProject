#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;



void B4051()
{
    int n,m;
    cin >> n>>m;
    vector<int> c(n);
    vector<int> a(m);
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    sort(c.begin(),c.end());
    int res=c[n-1];
    for(int i=0;i<m;i++){
        if(n == 1 ||m == 1 || a[i] > 0){
            res+=a[i];
        }
    }
    cout<<res<<endl;
}

#ifndef LUOGU_MAIN
int main()
{
    B4051();
    return 0;
}
#endif