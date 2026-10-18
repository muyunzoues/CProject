#include<iostream>
#include<vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;



void B4261(){
    int n;
    cin>>n;
    for(int i=1;i<2025;i++){
        int x=n & i;
        int y=n | i;
        if(x+y==2025){
            cout<<i<<endl;
            return;
        }
    }
    cout<<-1<<endl;
}

#ifndef LUOGU_MAIN
int main()
{
    B4261();
    return 0;
}
#endif