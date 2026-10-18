#include<iostream>
#include<vector>
#include <iomanip>
#include <cmath>
#include <climits>
using namespace std;


void B4575(){
    
    double d1,d2,d3;
    cin>>d1>>d2>>d3;
    
    if(d1>d3){
        cout<<1<<endl;
        return;
    }
    if(d2>d3){
        cout<<2<<endl;
        return;
    }
    int i=3;
    while(true){
        double temp=d1*d1+d2*d2;
        if(temp<=d3*d3){
           d1=d2;
           d2=sqrt(temp); 
           i++;
        }
        else{
            cout<<i<<endl;
            break;
        }
    }
}

#ifndef LUOGU_MAIN
int main()
{
    B4575();
    return 0;
}
#endif