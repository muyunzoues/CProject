#include<iostream>
#include<vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;



void B3957(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int res=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int tmp=nums[i]+nums[j];
            int tmp1=sqrt(tmp);
            if(tmp1*tmp1==tmp){
                res++;
            }
        }
    }
    cout<<res<<endl;
}

#ifndef LUOGU_MAIN
int main()
{
    B3957();
    return 0;
}
#endif