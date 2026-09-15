#include<iostream>
#include<vector>
#include <iomanip>
using namespace std;
void B4445(){
    double v,g,m,n;
    cin>>v>>g>>m>>n;
    double res1=v/2;
    double res2;
    if(g<300){
        res2=m;
    }
    else{
        res2=n;
    }
    if(res1>res2){
        cout<<fixed<<setprecision(1)<<res2<<endl;
    }
    else{
        cout<<fixed<<setprecision(1)<<res1<<endl;
    }
}

#ifndef LUOGU_MAIN
int main()
{
    B4445();
    return 0;
}
#endif