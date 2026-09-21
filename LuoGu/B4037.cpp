#include<iostream>
#include<vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;

void B4037(){
    int n;
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++){
            if(j==1||j==n||i==j){
                cout<<"+";
            }
            else{
                cout<<"-";
            }
        }
        cout<<endl;
    }
}

#ifndef LUOGU_MAIN
int main()
{
    B4037();
    return 0;
}
#endif