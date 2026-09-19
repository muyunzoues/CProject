#include<iostream>
#include<vector>
#include <iomanip>
#include <cmath>
#include <climits>
using namespace std;
//判断一个数是否为素数
bool isSu(int n){
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
void B3840(){
   int A,B;
   cin>>A>>B;
   int res=0;
   for(int i=A;i<=B;i++){
       if(isSu(i)){
           res++;
       }
   }
    cout<<res<<endl;
}

#ifndef LUOGU_MAIN
int main()
{
    B3840();
    return 0;
}
#endif