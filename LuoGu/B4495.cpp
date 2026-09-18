#include<iostream>
#include<vector>
#include <iomanip>
#include <cmath>
#include <climits>
using namespace std;
void B4495(){
    int h1,h2,h3,h4;
    cin>>h1>>h2>>h3>>h4;
    int tmp1=abs(h1-h2);
    int tmp2=abs(h1-h3);
    int tmp3=abs(h1-h4);
    int tmp=min(tmp1,min(tmp2,tmp3));
    int res=INT_MAX;
    if(tmp==tmp1){
        res=min(res,h2);
    }
    if(tmp==tmp2){
        res=min(res,h3);
    }
    if(tmp==tmp3){
        res=min(res,h4);
    }
    cout<<res<<endl;
}

#ifndef LUOGU_MAIN
int main()
{
    B4495();
    return 0;
}
#endif