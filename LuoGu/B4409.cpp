#include<iostream>
#include<vector>
#include <iomanip>
using namespace std;
void B4409(){
    int x,y,n,p;
    cin>>x>>y>>n>>p;
    double res;
    if(p<x){
        res=(double)p*n/10;
        cout<<fixed<<setprecision(2)<<res<<endl;
    }
    else if(p-y<p*n/10){
        res=(double)p-y;
        cout<<fixed<<setprecision(2)<<res<<endl;
    }
    else{
        res=(double)p*n/10;
        cout<<fixed<<setprecision(2)<<res<<endl;
    }
}

#ifndef LUOGU_MAIN
int main()
{
    B4409();
    return 0;
}
#endif