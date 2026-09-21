#include<iostream>
#include<vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;
//求解四次方跟
int isFourthPower(int n) {
    if (n < 0) return -1;          // 负数不可能是 4 次方（整数范围）
    int r = (int)sqrt(n);
    if (r * r != n) return -1;     // 先判断是不是完全平方数
    int root = (int)sqrt(r);
    if(root*root==r){
        return root;
    }     
    else{
        return -1;
    }    // 再判断根是不是完全平方数
}
void B4064(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    for(int i=0;i<n;i++){
        cout<<isFourthPower(nums[i])<<endl;
    }

}

#ifndef LUOGU_MAIN
int main()
{
    B4064();
    return 0;
}
#endif