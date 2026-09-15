#include<iostream>
#include<vector>
#include <iomanip>
using namespace std;
void B4354(){
    int m,n;
    cin>>m>>n;
    for(int i=1;i<=m*n;i++){
        if(i%m==0&&i%n==0){
            cout<<i<<endl;
            break;
        }
    }
}

#ifndef LUOGU_MAIN
int main()
{
    B4354();
    return 0;
}
#endif