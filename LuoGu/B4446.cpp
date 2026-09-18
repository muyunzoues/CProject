#include<iostream>
#include<vector>
#include <iomanip>
using namespace std;
void B4446(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    for(int i=0;i<n;i++){
        if(nums[i]<=10){
            cout<<"R"<<endl;
        }
        else if(nums[i]<=20){
            cout<<"L"<<endl;
        }
        
        else{
            cout<<nums[i]<<endl;
        }
    }
}

#ifndef LUOGU_MAIN
int main()
{
    B4446();
    return 0;
}
#endif