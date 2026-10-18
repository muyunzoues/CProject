#include<iostream>
#include<vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;



void B3956(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int res=0;
    for(int i=0;i<n;i++){
        if(s[i]>='A' && s[i]<='Z'){
            int ascs=s[i];//获取大写字母的ASCII码
            res+=-ascs;
        }
        else{
            int ascs=s[i]-'a'+1;//将小写字母转换为1-26的数字
            res+=ascs;
        }
    }
    cout<<res<<endl;

}

#ifndef LUOGU_MAIN
int main()
{
    B3956();
    return 0;
}
#endif