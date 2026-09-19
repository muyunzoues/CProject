#include<iostream>
#include<vector>
#include <iomanip>
#include <cmath>
#include <climits>
using namespace std;
void B4552(){
    double n;
    vector<double> nums;
    while(cin>>n){
        nums.push_back(n);
    }
    double res=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]>800){
            res+=(nums[i]-800)*0.2;
        }
    }
    cout<<fixed<<setprecision(2)<<res<<endl;
}

#ifndef LUOGU_MAIN
int main()
{
    B4552();
    return 0;
}
#endif