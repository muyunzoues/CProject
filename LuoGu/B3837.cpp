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
    int temp=0;
    for(int i=0;i<n;i++){
        string str;
        temp+=i;
        for(int j=temp;j<i+temp+1;j++){
           str+=words[j%26];
        }
        cout<<str<<endl;
    }
}

#ifndef LUOGU_MAIN
int main()
{
    B3844();
    return 0;
}
#endif