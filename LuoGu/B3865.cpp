#include<iostream>
#include<vector>
#include <iomanip>
#include <cmath>
#include <climits>
using namespace std;

//对角线与副对角线为+，其他为-
void B3865(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) cout<<"+";
            else if(i+j==n-1) cout<<"+";
            else cout<<"-";
        }
        cout<<endl;
    }
}

#ifndef LUOGU_MAIN
int main()
{
    B3865();
    return 0;
}
#endif