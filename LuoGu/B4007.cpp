#include<iostream>
#include<vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;

//将一个数拆分为每一位的数字
vector<int> getNum(int n) {
    vector<int> res;
    int temp=10;
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
void B4007(){
    int n,k;
    cin>>n>>k;
    int res=0;
    for(int i=1;i<=n;i++){
        vector<int> nums=getNum(i);
        for(int num:nums){
            if(num==k){
                res++;
            }
        }
    }
    cout<<res<<endl;
    
}

#ifndef LUOGU_MAIN
int main()
{
    B4007();
    return 0;
}
#endif