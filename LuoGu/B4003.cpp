#include<iostream>
#include<vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;

string swapString(string &s,int i,int j){
    while(i<j){
        char temp=s[i];
        s[i]=s[j];
        s[j]=temp;
        i++;
        j--;
    }
    return s;
}


void B4003(){
    int n;
    cin>>n;
    n=n%26;
    string s="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string res=swapString(s,0,n-1);
    res=swapString(res,n,res.size()-1);
    res=swapString(res,0,res.size()-1);
    cout<<res<<endl;
}

#ifndef LUOGU_MAIN
int main()
{
    B4003();
    return 0;
}
#endif