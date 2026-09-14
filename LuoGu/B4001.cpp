#include<iostream>
#include<vector>
using namespace std;
void B4001(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        if(i*i*i==n){
            cout<<"Yes"<<endl;
            return;
        }
    }
    cout<<"No"<<endl;
}

#ifndef LUOGU_MAIN
int main()
{
    B4001();
    return 0;
}
#endif