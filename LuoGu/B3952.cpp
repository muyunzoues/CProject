#include<iostream>
#include<vector>
using namespace std;
void B3952(){
    int m;
    cin>>m;
    int res1,res2;
    res1=m/13;
    res2=m%13;
    cout<<res1<<endl;
    cout<<res2<<endl;
}

#ifndef LUOGU_MAIN
int main()
{
    B3952();
    return 0;
}
#endif