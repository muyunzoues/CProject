#include<iostream>
#include<vector>
#include <iomanip>
using namespace std;
void B4258(){
    int n;
    cin>>n;
    vector<int> nums(n);
    int num;
    for(int i=0;i<n;i++){
        cin>>num;
        nums[i]=num;
    }
    for(int i=0;i<n;i++){
        if(nums[i]%10<5){
            cout<<nums[i]/10*10<<endl;
        }
        else{
            cout<<(nums[i]/10+1)*10<<endl;
        }
    }
}

#ifndef LUOGU_MAIN
int main()
{
    B4258();
    return 0;
}
#endif