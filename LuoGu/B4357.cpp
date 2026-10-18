#include<iostream>
#include<vector>
#include <iomanip>
#include <cmath>
#include <climits>
using namespace std;
void B4357(){
    int l,r;
    cin>>l>>r;
    int res=0;
    for(int x=1;x<=r;x*=2){
        for(int y=x;y<=r;y*=2){
            int sum=x+y;
            if(sum>=l && sum<=r){
                res++;
            }
        }
    }
    cout<<res<<endl;
}

#ifndef LUOGU_MAIN
int main()
{
    B4357();
    return 0;
}
#endif