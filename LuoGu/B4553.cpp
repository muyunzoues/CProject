#include<iostream>
#include<vector>
#include <iomanip>
#include <cmath>
#include <climits>
using namespace std;


void B4553(){
    int l,r;
    cin>>l>>r;
    int res=0;
    for(int i=l;i<=r;i++){
        int temp=sqrt(i);
        if(temp*temp==i){
            res++;
        }
    }
    cout<<res<<endl;
}

#ifndef LUOGU_MAIN
int main()
{
    B4553();
    return 0;
}
#endif