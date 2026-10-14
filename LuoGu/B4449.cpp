#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;
int getWordNums(string s){
    int res=0;
    for(int i=0;i<s.length();i++){
        if(s[i]-'A'>=0 && s[i]-'A'<26 ){
            res++;
        }
    }
    return res;
}
int getNumNums(string s){
    int res=0;
    for(int i=0;i<s.length();i++){
        if(s[i]>='0' && s[i]<='9' ){
            res++;
        }
    }
    return res;
}
void B4449()
{
    int n;
    cin >> n;
    vector<string> ss(n);
    for(int i=0;i<n;i++){
        cin>>ss[i];
    }
    for(int i=0;i<n;i++){
        if(ss[i].length()>=8 && getWordNums(ss[i])>0 && getNumNums(ss[i])>0){
            cout<<"Y"<<endl;
        }
        else{
            cout<<"N"<<endl;
        }
    }
}

#ifndef LUOGU_MAIN
int main()
{
    B4449();
    return 0;
}
#endif