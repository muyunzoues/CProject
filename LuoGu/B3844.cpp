#include<iostream>
#include<vector>
#include <iomanip>
#include <cmath>
#include <climits>
using namespace std;
void B3844(){
    int n;
    cin>>n;
    //将26个字母存入vector中
    vector<char> words;
    for(char i='A';i<='Z';i++){
        words.push_back(i);
    }
    vector<string> res;
    for(int i=0;i<n;i++){
        string str;
        int temp=i;
        for(int j=i;j<n+temp;j++){
           str+=words[j%26];
        }
        res.push_back(str);
    }
    for(const auto& s : res){
        cout<<s<<endl;
    }
}

#ifndef LUOGU_MAIN
int main()
{
    B3844();
    return 0;
}
#endif