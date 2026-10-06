#include<iostream>
#include<vector>
#include <iomanip>
#include <cmath>
#include <climits>
using namespace std;
void B4356(){
    int n;
    cin>>n;
    int res=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if (i*j%2==0)
            {
                res++;
            }
            
        }
    }
    cout<<res<<endl;
}

#ifndef LUOGU_MAIN
int main()
{
    B4356();
    return 0;
}
#endif