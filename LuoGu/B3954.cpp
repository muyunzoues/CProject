#include<iostream>
#include<vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;


void B3954(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int mul=1;
    for(int i=0;i<n;i++){
        mul*=nums[i];
        if(mul>1000000){
            break;
        }
    }
    if (mul>1000000)
    {
        cout<<">1000000"<<endl;
    }
    else{
        cout<<mul<<endl;
    }
    
}

#ifndef LUOGU_MAIN
int main()
{
    B3954();
    return 0;
}
#endif