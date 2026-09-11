#include<iostream>
#include<vector>
using namespace std;
void B3863(){
    vector<int> nums;
    int n;
    // 循环读取，直到输入结束
    while (cin >> n) {
        nums.push_back(n);
    }
    if(nums[3]>nums[0]*2+nums[1]*5+nums[2]*3||nums[3]==nums[0]*2+nums[1]*5+nums[2]*3){
        cout<<"Yes"<<endl;
        cout<<nums[3]-nums[0]*2-nums[1]*5-nums[2]*3<<endl;
    }
    else{
        cout<<"No"<<endl;
        cout<<nums[0]*2+nums[1]*5+nums[2]*3-nums[3]<<endl;
    }
}

#ifndef LUOGU_MAIN
int main()
{
    B3863();
    return 0;
}
#endif