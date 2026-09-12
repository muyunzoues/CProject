#include<iostream>
#include<vector>
using namespace std;
void B3864(){
    int k,L,R;
    cin>>k>>L>>R;
    int sum=0;
    for(int i=L;i<=R;i++){
        if(i%k==0||i%10==k){
            sum+=i;
        }
    }
    cout<<sum<<endl;
}

#ifndef LUOGU_MAIN
int main()
{
    B3864();
    return 0;
}
#endif