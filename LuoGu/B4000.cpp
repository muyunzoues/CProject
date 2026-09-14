#include<iostream>
#include<vector>
using namespace std;
void B4000(){
    int h,m,s,k;
    cin>>h>>m>>s>>k;
    int pre0=s+k;
    if(pre0>=60){
        m+=pre0/60;
        s=pre0%60;
    }
    else{
        s=pre0;
    }
    if(m>=60){
        h+=m/60;
        m=m%60;
    }
    if(h>=24){
        h=h%24;
    }
    cout<<h<<" "<<m<<" "<<s<<endl;
}

#ifndef LUOGU_MAIN
int main()
{
    B4000();
    return 0;
}
#endif