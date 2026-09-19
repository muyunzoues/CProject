#include<iostream>
#include<vector>
#include <iomanip>
#include <cmath>
#include <climits>
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
//计算n的m次方
int getSum(int n,int m){
   int sum=1;
   for(int i=1;i<=m;i++){
       sum*=n;
   }
   return sum;
}

void B3841(){
   int M;
   cin>>M;
   vector<int> nums(M);
   for(int i=0;i<M;i++){
       cin>>nums[i];
   }
   for(int i=0;i<M;i++){
       vector<int> temp=getNum(nums[i]);
       int sum=0;
       for(int j=0;j<temp.size();j++){
           sum+=getSum(temp[j],temp.size());
       }
       if(sum==nums[i]){
           cout<<"T"<<endl;
       }
       else{
           cout<<"F"<<endl;
       }
   }

}

#ifndef LUOGU_MAIN
int main()
{
    B3841();
    return 0;
}
#endif