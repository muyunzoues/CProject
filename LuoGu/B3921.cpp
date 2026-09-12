#include<iostream>
#include<vector>
using namespace std;
void B3921(){
    int X,N;
    cin>>X>>N;
    int sum=X+N;
    if(sum%7==0){
        cout<<7<<endl;
    }
    else{
        cout<<sum%7<<endl;
    }
}

#ifndef LUOGU_MAIN
int main()
{
    B3921();
    return 0;
}
#endif