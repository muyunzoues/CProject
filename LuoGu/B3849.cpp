#include<iostream>
#include<vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;



void B3849(){
    int n,r;
    cin>>n>>r;
    string res="";
    //用do-while循环来处理n=0的情况
    do{
        int temp=n%r;
        if(temp<10){
            res+=char(temp+'0');
        }
        else{
            res+=char(temp-10+'A');
        }
        n/=r;
    }while(n>0);
    reverse(res.begin(),res.end());//do-while循环结束后，res中存储的是逆序的结果，需要反转
    cout<<res<<endl;
}

#ifndef LUOGU_MAIN
int main()
{
    B3849();
    return 0;
}
#endif