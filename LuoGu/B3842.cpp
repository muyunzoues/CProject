#include<iostream>
#include<vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;



void B3842(){
    int n,m;
    cin>>n>>m;
    vector<int> nums(m);
    for(int i=0;i<m;i++){
        cin>>nums[i];
    }
    vector<int> tmp(n,0);
    for(int i=0;i<m;i++){
        tmp[nums[i]]++;
    }
    int f=0;
    for(int i=0;i<n;i++){
        if(tmp[i]==0){
            cout<<i<<" ";
            f=1;
        }
    }
    if(f==0){
        cout<<n<<endl;
    }

}

#ifndef LUOGU_MAIN
int main()
{
    B3842();
    return 0;
}
#endif