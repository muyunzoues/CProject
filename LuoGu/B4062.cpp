#include<iostream>
#include<vector>
#include <iomanip>
using namespace std;
void B4062(){
    double K;
    cin>>K;
    double C=K-273.15;
    double F=C*1.8+32;
    if(F>212){
        cout<<"Temperature is too high!"<<endl;
    }
    else{
        //setprecision(2) 配合 fixed 表示四舍五入小数点后两位
        cout<<fixed<<setprecision(2)<<C<<" "<<fixed<<setprecision(2)<<F<<endl;
    }
}

#ifndef LUOGU_MAIN
int main()
{
    B4062();
    return 0;
}
#endif