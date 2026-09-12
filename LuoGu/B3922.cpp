#include<iostream>
#include<vector>
using namespace std;
void B3922(){
    int N,M;
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        if(i%M==0){
            continue;
        }
        else{
            cout<<i<<endl;
        }
    }
}

#ifndef LUOGU_MAIN
int main()
{
    B3922();
    return 0;
}
#endif