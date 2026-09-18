#include<iostream>
#include<vector>
#include <iomanip>
#include <cmath>
#include <climits>
using namespace std;
void B4496(){
    int n;
    cin>>n;
    vector<int> nums;
    while(n>0){
        int tmp=n%10;
        nums.push_back(tmp);
        n/=10;
    }
    for(int i=nums.size()-1;i>=0;i--){
        if(nums[i]==4){
            nums[i]=8;
        }
    }
    int res=0;
    int base=1;
    for(int i=0;i<nums.size();i++){
        res+=nums[i]*base;
        base*=10;
    }
    cout<<res<<endl;
}

#ifndef LUOGU_MAIN
int main()
{
    B4496();
    return 0;
}
#endif