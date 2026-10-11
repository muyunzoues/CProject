#include<iostream>
#include<vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;

int getSum(vector<int> &nums,int i,int j){
    int sum=0;
    for(int k=i;k<=j;k++){
        sum+=nums[k];
    }
    return sum;
}


void B4038(){
    int t;
    cin>>t;
    vector<vector<int>> nums(t);
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        vector<int> temp(n);
        for(int j=0;j<n;j++){
            cin>>temp[j];
        }
        nums[i]=temp;
    }
    for (int i = 0; i < t; i++) {
    int n = nums[i].size();
    vector<long long> pre(n + 1, 0);
    for (int k = 0; k < n; k++) {
        pre[k + 1] = pre[k] + nums[i][k];
    }
    
    bool flag = false;
    for (int j = 0; j < n - 1; j++) {   // 注意 j 的范围
        if (2 * pre[j + 1] == pre[n]) {
            flag = true;
            break;
        }
    }
    cout << (flag ? "Yes" : "No") << endl;
}
}

#ifndef LUOGU_MAIN
int main()
{
    B4038();
    return 0;
}
#endif