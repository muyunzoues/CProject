#include<iostream>
#include<vector>
#include <iomanip>
#include <cmath>
#include <climits>
using namespace std;
void B4447(){
    int n;
    cin>>n;
    vector<vector<int>>  nums(n,vector<int>(2));
    for(int i=0;i<n;i++){
        cin>>nums[i][0]>>nums[i][1];
    }
    vector<int> res(n);
    for(int i=0;i<n;i++){
        int sum=nums[i][0]+nums[i][0]/nums[i][1];
        res[i]=sum;
    }
    for(int i=0;i<n;i++){
        cout<<res[i]<<endl;
    }
}

#ifndef LUOGU_MAIN
int main()
{
    B4447();
    return 0;
}
#endif