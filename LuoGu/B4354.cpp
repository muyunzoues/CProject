#include<iostream>
#include<vector>
#include <iomanip>
using namespace std;
void B42354(){
    int n,k,t;
    cin>>n>>k>>t;
    int temp=k*t;
    if(temp>=n){
        cout<<n<<endl;
    }
    else{
        cout<<temp<<endl;
    }
}

#ifndef LUOGU_MAIN
int main()
{
    B42354();
    return 0;
}
#endif