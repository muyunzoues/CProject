#include<iostream>
#include<vector>
#include <iomanip>
#include <cmath>
#include <climits>
using namespace std;
void B4448(){
    int h,w,x;
    cin>>h>>w>>x;
    int res=0;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            //要将两边同时平方，不能开根号后比较两边，会有精读误差
            int l=i*i+j*j;
            int r=(x+i-j)*(x+i-j);
            if(l<=r){
                res++;
            }
        }
    }
    cout<<res<<endl;
}

#ifndef LUOGU_MAIN
int main()
{
    B4448();
    return 0;
}
#endif