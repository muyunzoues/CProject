#include<iostream>
#include<vector>
#include <iomanip>
using namespace std;
void B4410(){
    int n;
    cin>>n;
    int res=0;
    for(int i=n;i>=1;i--){
        res+=i*i;
    }
    cout<<res<<endl;
}

#ifndef LUOGU_MAIN
int main()
{
    B4410();
    return 0;
}
#endif