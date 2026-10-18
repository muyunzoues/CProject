#include<iostream>
#include<vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_map>
using namespace std;

// 计算一个集合的整数的二进制表示中 1 的个数
int getNumsOne(vector<int> &nums){
    int res = 0;
    for(int i = 0; i < nums.size(); i++){
        int temp = nums[i];   // 复制一份
        int cnt = 0;
        while(temp > 0){
            cnt += temp & 1;//最低位是 1 就加 1
            temp >>= 1;
        }
        res += cnt;
    }
    return res;
}

void B4358(){
   int n;
   cin>>n;
   vector<int> nums(n);
   for(int i=0;i<n;i++){
    cin>>nums[i];
   }
   cout<<getNumsOne(nums)<<" ";
   if(getNumsOne(nums)%2==0){
    cout<<0<<endl;
   }
   else{
    cout<<1<<endl;
   }
    
}

#ifndef LUOGU_MAIN
int main()
{
    B4358();
    return 0;
}
#endif