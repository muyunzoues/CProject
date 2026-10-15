#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;


void B4578()
{
    string ss;
    getline(cin,ss);
    vector<string> res;
    int need=1;
    int i=0,j=0;
    while(j<ss.length()){
        while(ss[j]!=' '){
            j++;
        }
        res.push_back(ss.substr(i,j-i));
        

    }
}

#ifndef LUOGU_MAIN
int main()
{
    B4578();
    return 0;
}
#endif