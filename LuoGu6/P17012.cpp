#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <numeric>
#include <stack>
using namespace std;

void P17012()
{
    int n;
    cin >> n;
    vector<int> p(1005);
    vector<long long> dp(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for(int j=1;j<=i;j++){
            dp[i]=max(dp[i],dp[i-j]+p[j]);
        }
    }
    cout<<dp[n]<<endl;
    
}

#ifndef LUOGU_MAIN
int main()
{
    P17012();
    return 0;
}
#endif