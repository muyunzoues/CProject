#include<iostream>
#include<vector>
#include <iomanip>
#include <cmath>
#include <climits>
using namespace std;
void B4573(){
    double m,n,p;
    cin>>m>>n>>p;
    double tmp1=(double)1000/n+p;
    if(tmp1>m){
        cout<<"turtle"<<endl;
    } else if(tmp1<m){
        cout<<"rabbit"<<endl;
    } else {
        cout<<"tie"<<endl;
    }
    cout<<fixed<<setprecision(2)<<tmp1<<endl;
}

#ifndef LUOGU_MAIN
int main()
{
    B4573();
    return 0;
}
#endif