#include<iostream>
#include<vector>
using namespace std;
void B3953(){
    int m;
    cin>>m;
    vector<int> res;
    for(int i=1;i<=m;i++){
        if(m%i==0){
            res.push_back(i);
        }
    }
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<endl;
    }
}

#ifndef LUOGU_MAIN
int main()
{
    B3953();
    return 0;
}
#endif