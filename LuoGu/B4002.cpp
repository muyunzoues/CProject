#include<iostream>
#include<vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;
//判断是否存在连个数a，b使得a² + b² = n
bool isSumOfTwoSquares(int n) {
    for (int a = 1; a * a < n; a++) {   // a 从 1 开始，且 a*a < n 保证 b 至少为 1
        int rest = n - a * a;
        if (rest <= 0) continue;         // 剩下的部分必须为正
        int b = (int)sqrt(rest);         //开方
        if (b >= 1 && b * b == rest) {   // b 也必须是正整数
            return true;
        }
    }
    return false;
}

void B4002(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    for(int i=0;i<n;i++){
        if(isSumOfTwoSquares(nums[i])){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    
}

#ifndef LUOGU_MAIN
int main()
{
    B4002();
    return 0;
}
#endif