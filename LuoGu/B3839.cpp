#include<iostream>
#include<vector>
using namespace std;
int getSum(int n){
   int sum=0;
   for(int i=1;i<=n;i++){
       sum+=i;
   }
   return sum;
}
void B3839(){
    int n;
    cin >> n;
    int res=0;
    for(int i=1;i<=n;i++){
        res+=getSum(i);
    }
    cout << res << endl;
}
#ifndef LUOGU_MAIN
int main()
{
    B3839();
    return 0;
}
#endif