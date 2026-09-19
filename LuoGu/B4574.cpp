#include<iostream>
#include<vector>
#include <iomanip>
#include <cmath>
#include <climits>
using namespace std;
void B4574(){
    int n;
    cin>>n;
    int res=0;
    int count=1;
    for(int i=1;i<=n;i++){
        res+=count;
        count*=2;
    }
    cout<<res<<endl;
}

#ifndef LUOGU_MAIN
int main()
{
    B4574();
    return 0;
}
#endif