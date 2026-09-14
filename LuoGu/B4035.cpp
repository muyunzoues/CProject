#include<iostream>
#include<vector>
using namespace std;
void B4035(){
    int n;
    cin>>n;
    vector<int> nums(n);
    int num;
    for(int i=0;i<n;i++){
        cin>>num;
        nums[i]=num;
    }
    int res=0;
    for(int i=0;i<n;i++){
        if(nums[i]%9==0&&nums[i]%8!=0){
            res++;
        }
    }
    cout<<res<<endl;
}

#ifndef LUOGU_MAIN
int main()
{
    B4035();
    return 0;
}
#endif