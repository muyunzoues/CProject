#include<iostream>
#include<vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;


void B3955(){
    int n;
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        if(i==(n+1)/2||i==1||i==n){
            for(int j = 1; j <= n; j++){
                if(j==1||j==n){
                    cout<<"|";
                }
                else{
                    cout<<"-";
                }
            }
        }
        else{
            for(int j = 1; j <= n; j++){
                if(j==1||j==n){
                    cout<<"|";
                }
                else{
                    cout<<"x";
                }
            }
        }
        cout<<endl;
    }
    
}

#ifndef LUOGU_MAIN
int main()
{
    B3955();
    return 0;
}
#endif