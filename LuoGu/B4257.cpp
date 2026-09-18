#include<iostream>
#include<vector>
#include <iomanip>
using namespace std;
void B4257(){
    int n,x,y;
    cin>>n>>x>>y;
    //double mid = y / x;    先算整数除法 7/3 = 2，再转成 2.0，结果错误！
    double mid=(double)y/x;
    int temp=(int)mid;
    if(temp==mid){
        cout<<n-temp<<endl;
    }
    else{
        cout<<n-temp-1<<endl;
    }
}

#ifndef LUOGU_MAIN
int main()
{
    B4257();
    return 0;
}
#endif