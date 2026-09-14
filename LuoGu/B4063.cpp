#include<iostream>
#include<vector>
#include <iomanip>
using namespace std;
void B4063(){
    int n;
    cin>>n;
    vector<int> nums(n);
    int num;
    for(int i=0;i<n;i++){
        cin>>num;
        nums[i]=num;
    }
    int res1=0,res2=0;
    for(int i=0;i<n;i++){
        if(nums[i]%2!=0){
            res1++;
        }
        else{
            res2++;
        }
    }
    cout<<res1<<" "<<res2<<endl;
}

#ifndef LUOGU_MAIN
int main()
{
    B4063();
    return 0;
}
#endif