#include<iostream>
#include<vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;




void B4004(){
    int t;
    cin>>t;
    vector<vector<int>> nums(t);
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        vector<int> temp(n);
        for(int j=0;j<n;j++){
            cin>>temp[j];
        }
        sort(temp.begin(),temp.end());
        nums[i]=temp;
    }
    for(int i=0;i<t;i++){
        int j=nums[i].size()-1;
        while(j>=0){
            if(nums[i][nums[i].size()-1]%nums[i][j]==0){
                j--;
            }
            else{
                break;
            }
        }
        if(j<0){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
}

#ifndef LUOGU_MAIN
int main()
{
    B4004();
    return 0;
}
#endif