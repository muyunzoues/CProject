#include <iostream>
using namespace std;

void B3847()
{
   int h,m,s;
   char w;
   cin >> h >> m >> s >> w;
   int hh;
   if(w=='A'){
    hh=h%12;          // 12A 是午夜，归零
   }else{
    hh=h%12+12;       // 12P 是中午，其余加 12 小时
   }
   int res=hh*60*60+m*60+s;
   cout << res << endl;
}

#ifndef LUOGU_MAIN
int main()
{
   B3847();
   return 0;
}
#endif
