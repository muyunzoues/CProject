#include<iostream>
#include<vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;



void B3868(){
    int n;
    cin>>n;
    vector<string> ss(n);
    for(int i=0;i<n;i++){
        cin>>ss[i];
    }
    for(int i=0;i<n;i++){
        int flag0=1;
        int flag1=1;
        int flag2=1;
        int flag3=1;
        for(int j=0;j<ss[i].size();j++){
            if(ss[i][j]>'1'){
                flag0=0;
            }
            if(ss[i][j]>'7'){
                flag1=0;
            }
            if(ss[i][j]>'9'){
                flag2=0;
            }
            if(ss[i][j]>'F'){
                flag3=0;
            }
        }
        cout<<flag0<<" "<<flag1<<" "<<flag2<<" "<<flag3<<endl;
    }
}

#ifndef LUOGU_MAIN
int main()
{
    B3868();
    return 0;
}
#endif