#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

void B4500()
{
    string ss1,ss2,ss3;
    cin>>ss1>>ss2>>ss3;
    int dis=ss2[0]-ss1[0];
    string temp1=ss3.substr(dis,ss3.length()-dis);
    string res=temp1+ss3.substr(0,dis);
    cout<<res<<endl;
}

#ifndef LUOGU_MAIN
int main()
{
    B4500();
    return 0;
}
#endif