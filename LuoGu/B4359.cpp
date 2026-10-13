#include<iostream>
#include<vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_map>
using namespace std;



void B4359(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    long long res=0;
    int last=0; //前一个小朋友分到的糖果数
    for(int i=0;i<n;i++){
        int cur=max(nums[i],last+1); // 贪心取最小值
        res+=cur;
        last=cur;//更新前一个小朋友分到的糖果数
    }
    cout<<res<<endl;
}

#ifndef LUOGU_MAIN
int main()
{
    B4359();
    return 0;
}
#endif