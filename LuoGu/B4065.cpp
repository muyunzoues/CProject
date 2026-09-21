#include<iostream>
#include<vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;
//将一个数拆分为每一位的数字
vector<int> getNum(long long n) {
    vector<int> res;
    long long temp=10;
    while(true){
        if(n<temp){
            res.push_back(n);
            break;
        }
        res.push_back(n%temp);
        n/=temp;
    }
    return res;
}
void B4065(){
    int n;
    cin >> n;
    vector<long long> nums(n);  // 修改点：将 int 改为 long long
    for(int i = 0; i < n; i++){
        cin >> nums[i];         
    }
    int res = INT_MIN;
    for(int i = 0; i < n; i++){
        vector<int> temp = getNum(nums[i]); 
        int sum = 0;
        for(int t : temp){
            sum += t;
        }
        res = max(res, sum);
    }
    cout << res << endl;
}

#ifndef LUOGU_MAIN
int main()
{
    B4065();
    return 0;
}
#endif