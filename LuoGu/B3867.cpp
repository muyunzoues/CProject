#include<iostream>
#include<vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;



void B3867(){
    int n,d;
    cin>>n>>d;
    vector<int> nums(d);
    for(int i=0;i<d;i++){
        cin>>nums[i];
    }
    vector<int> tmp(n,0);
    for(int i=0;i<d;i++){
        tmp[nums[i]]+=i+1;
    }
    for(int i=0;i<n;i++){
        cout<<tmp[i]<<" ";
    }

}

#ifndef LUOGU_MAIN
int main()
{
    B3867();
    return 0;
}
#endif