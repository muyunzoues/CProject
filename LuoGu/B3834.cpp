#include <iostream>
using namespace std;
void B3834(){
    int n;
    cin >> n;
    int res=0;
    int x=1,y=n;
    while(x<=y){
       if(x*y==n){
           res++;
           x++;
           y--;
       }
       else if(x*y<n){
           x++;
       }
       else{
           y--;
       }
    }
    cout << res << endl;
}

#ifndef LUOGU_MAIN
int main()
{
    B3834();
    return 0;
}
#endif