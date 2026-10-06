#include<iostream>
#include<vector>
#include <iomanip>
#include <cmath>
#include <climits>
using namespace std;
//将一个数拆分为每一位的数字
vector<int> getNum(long long n) {
    vector<int> res;
    long long temp=10;
    while(true){
        if(n<temp){
            res.push_back(n);
            break;
        }
        res.push_back(n%temp);
        n/=temp;
    }
    return res;
}
//判断一个数的每一位是否相同
bool isSame(vector<int> &a) {
    for(int i=1;i<a.size();i++){
        if(a[i]!=a[0]){
            return false;
        }
    }
    return true;
}
void B4411(){
    long long n;
    cin >> n;
    int res=0;
    for(int i = 1; i <= n; i++){
        vector<int> temp = getNum(i); 
        if(isSame(temp)){
            res++;
        }
    }
    cout << res << endl;
}

#ifndef LUOGU_MAIN
int main()
{
    B4411();
    return 0;
}
#endif