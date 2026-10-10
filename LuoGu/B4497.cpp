#include<iostream>
#include<vector>
#include <iomanip>
#include <cmath>
#include <climits>
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

void B4497(){
    int L,R;
    cin >> L >> R;
    int res=0;
    for(int i = L; i <= R; i++){
        int temp=i;
        vector<int> nums=getNum(temp);
        int sum=0;
        for(int j=0;j<nums.size();j++){
            if(nums[j]==2){
                sum++;
            }
        }
        if(sum==3){
            res++;
        }
    }
    cout << res << endl;
}

#ifndef LUOGU_MAIN
int main()
{
    B4497();
    return 0;
}
#endif