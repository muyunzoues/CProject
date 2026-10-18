#include<iostream>
#include<vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;

void B4259 (){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int t=0;
        for(int j=1;j<=m;j++){
            cout<<i+t<<" ";
            t+=i;
        }
        cout<<endl;
    }
}

#ifndef LUOGU_MAIN
int main()
{
    B4259 ();
    return 0;
}
#endif