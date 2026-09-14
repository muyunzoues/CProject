#include<iostream>
#include<vector>
using namespace std;
void B4001(){
    int n,a,b;
    cin>>n>>a>>b;
    int i=1;
    while(true){
        if(i*a+i*b<=n){
            i++;
        }
        else {
            cout<<i-1<<endl;
            return;
        }
    }
}

#ifndef LUOGU_MAIN
int main()
{
    B4001();
    return 0;
}
#endif