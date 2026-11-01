#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;

//判断是否为质数
bool isZhi(int num){
    if(num==1){
        return false;
    }
    for(int i=2;i*i<=num;i++){
        if(num%i==0){
            return false;
        }
    }
    return true;
}

void B4050()
{
    int t;
    cin >> t;
    vector<int> nums(t);
    for (int i = 0; i < t; i++)
    {
        cin >> nums[i];
    }
    for (int i = 0; i < t; i++)
    {
        int res=1;
        int count=1;
        int tmp=nums[i];
        while(tmp>0){
            if(isZhi(tmp)){
                cout<<res<<endl;
                break;
            }
            tmp-=count;
            if(tmp==0){
                cout<<res<<endl;
                break;
            }
            res++;
            count*=2;
        }
        if(tmp<0){
            cout<<-1<<endl;
        }
    }
}

#ifndef LUOGU_MAIN
int main()
{
    B4050();
    return 0;
}
#endif