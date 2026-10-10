#include<iostream>
#include<vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;



void B3843(){
    string s;
    cin>>s;
    vector<string> ss;
    //将字符串按逗号分割
    for(int i=0;i<s.size();i++){
        if(s[i]==','){
            continue;
        }
        string temp="";
        while(i<s.size() && s[i]!=','){
            temp+=s[i];
            i++;
        }
        ss.push_back(temp);
    }
    //遍历每个分割后的字符串，判断是否符合要求
    for(int i=0;i<ss.size();i++){
        if(ss[i].size()>12 || ss[i].size()<6){
            continue;
        }
        int flag0=0;
        int flag1=0;
        int flag2=0;
        int flag3=0;
        int flag4=0;
        for(int j=0;j<ss[i].size();j++){
            if(!((ss[i][j]>='0' && ss[i][j]<='9') || (ss[i][j]>='a' && ss[i][j]<='z') || (ss[i][j]>='A' && ss[i][j]<='Z') || ss[i][j]=='!' || ss[i][j]=='#' || ss[i][j]=='$' || ss[i][j]=='@')){
                flag0=1;
                break;
            }
            if(ss[i][j]>='0' && ss[i][j]<='9'){
                flag1=1;
            }
            else if(ss[i][j]>='a' && ss[i][j]<='z'){
                flag2=1;
            }
            else if(ss[i][j]>='A' && ss[i][j]<='Z'){
                flag3=1;
            }
            else{
                flag4=1;
            }
        }
        if(flag0==0 && ((flag1==1&&flag2==1) || (flag1==1&&flag3==1) || (flag2==1&&flag3==1)) && flag4==1){
            cout<<ss[i]<<endl;
        }
    }

}

#ifndef LUOGU_MAIN
int main()
{
    B3843();
    return 0;
}
#endif