#include <iostream>
using namespace std;
bool getRun(int year)
{
    if(year%400==0)
    {
        return true;
    }
    else if(year%100==0)
    {
        return false;
    }
    else if(year%4==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void B3835(){
    int A,B;
    cin >> A >> B;
    int res;
    if(B==1|| B==3 || B==5 || B==7 || B==8 || B==10 || B==12)
    {
        res=31;
    }
    else if(B==4 || B==6 || B==9 || B==11)
    {
        res=30;
    }
    else
    {
        if(getRun(A))
        {
            res=29;
        }
        else
        {
            res=28;
        }
    }
    cout << res << endl;
}

#ifndef LUOGU_MAIN
int main()
{
    B3835();
    return 0;
}
#endif