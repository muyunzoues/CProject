#include <iostream>
using namespace std;
void B3846()
{
    int a, b;
    cin >> a >> b;
    int sum=0;
    for(int i = a+1; i < b; i++)
    {
        if(i%400==0)
        {
            sum+=i;
        }
        else if(i%100==0)
        {
            continue;
        }
        else if(i%4==0)
        {
            sum+=i;
        }
        else
        {
            continue;
        }
    }
    cout << sum << endl;
}

#ifndef LUOGU_MAIN
int main()
{
    B3846();
    return 0;
}
#endif