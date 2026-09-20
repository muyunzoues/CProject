#include<iostream>
#include<vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;


void B3924(){
    int n;
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        if(i==(n+1)/2){
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
                    cout<<"a";
                }
            }
        }
        cout<<endl;
    }
    
}

#ifndef LUOGU_MAIN
int main()
{
    B3924();
    return 0;
}
#endif