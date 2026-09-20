#include<iostream>
#include<vector>
#include <iomanip>
#include <cmath>
#include <climits>
using namespace std;
//判断一个数是否为完全平方数
bool isPerfectSquare(int n) {
    if (n < 0) return false;
    int root = (int)sqrt(n);
    // 检查 root 和 root+1，防止截断误差
    return root * root == n || (root + 1) * (root + 1) == n;
}
void B3845(){
    int n;
    cin>>n;
    int res=0;
    for(int i=1;i<n;i++){
        for(int j=i;j<n;j++){
            int temp=i*i+j*j;
            if(temp<=n*n&&isPerfectSquare(temp)){
                res++;
            }
        }
    }
    cout<<res<<endl;
}

#ifndef LUOGU_MAIN
int main()
{
    B3845();
    return 0;
}
#endif