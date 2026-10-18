#include<iostream>
#include<vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_map>
using namespace std;



void B4262(){
   int n;
   cin>>n;
   vector<string> ss(n);
   for(int i=0;i<n;i++){
         cin>>ss[i];
        }
    for(int i=0;i<n;i++){
        for(int j=0;j<ss[i].length();j++){
            ss[i][j]=tolower(ss[i][j]);//将字符串中的大写字母转换为小写字母
        }
    }
    unordered_map<string,int> mp;
    for(int i=0;i<n;i++){
        mp[ss[i]]++;//统计每个字符串出现的次数
    }
    int maxCount=INT_MIN;
    for(int i=0;i<n;i++){
        if(mp[ss[i]]>maxCount){
            maxCount=mp[ss[i]];
        }
    }
    for(int i=0;i<n;i++){
        if(mp[ss[i]]==maxCount){
            cout<<ss[i]<<endl;
            return;
        }
    }
}

#ifndef LUOGU_MAIN
int main()
{
    B4262();
    return 0;
}
#endif