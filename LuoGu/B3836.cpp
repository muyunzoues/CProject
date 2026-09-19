#include<iostream>
#include<vector>
#include <iomanip>
#include <cmath>
#include <climits>
using namespace std;

void B3836(){
    int x,y,z,n,m;
    cin>>x>>y>>z>>n>>m;
    int res=0;
    for(int i=0;i<=m;i++){
        for(int j=0;j<=m-i;j++){
            int k=m-i-j;
            if(i*x+j*y+k/z==n&&k%z==0){
                res++;
            }
        }
    }
    cout<<res<<endl;
}

#ifndef LUOGU_MAIN
int main()
{
    B3836();
    return 0;
}
#endif