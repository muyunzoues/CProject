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
void B4036(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    for(int i=0;i<n;i++){
       vector<int> tmp=getNum(nums[i]);
       int sum=0;
       for(int t:tmp){
        sum+=t;
       }
       if(sum%7==0){
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
    B4036();
    return 0;
}
#endif