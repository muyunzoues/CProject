#include<iostream>
#include<vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;

int getMax(vector<int> &nums){
    int maxNum=INT_MIN;
    for(int i=0;i<nums.size();i++){
        if(nums[i]>maxNum){
            maxNum=nums[i];
        }
    }
    return maxNum;
}

int getMin(vector<int> &nums){
    int minNum=INT_MAX;
    for(int i=0;i<nums.size();i++){
        if(nums[i]<minNum){
            minNum=nums[i];
        }
    }
    return minNum;
}


void B4066(){
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    for(int i=0;i<n;i++){
        int maxNum=getMax(nums);
        int minNum=getMin(nums);
        if(nums[i]<k){
            nums[i]=minNum;
        }
        if(nums[i]>k){
            nums[i]=maxNum;
        }
        cout<<nums[i]<<" ";
    }

}

#ifndef LUOGU_MAIN
int main()
{
    B4066();
    return 0;
}
#endif