#include<iostream>
#include<vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;
//判断闰年
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
//判断月份天数
int getDay(int y,int m){
    int res;
    if(m==1|| m==3 || m==5 || m==7 || m==8 || m==10 || m==12)
    {
        res=31;
    }
    else if(m==4 || m==6 || m==9 || m==11)
    {
        res=30;
    }
    else
    {
        if(getRun(y))
        {
            res=29;
        }
        else
        {
            res=28;
        }
    }
    return res;
}
void B4260 (){
    int y, m, d, h, k;
cin >> y >> m >> d >> h >> k;

// 1. 小时进位
h += k;
int days_to_add = h / 24;
h %= 24;
d += days_to_add;

// 2. 判断当前月有多少天
int days_in_month;
if (m == 2) {
    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
        days_in_month = 29;
    else
        days_in_month = 28;
} else if (m == 4 || m == 6 || m == 9 || m == 11) {
    days_in_month = 30;
} else {
    days_in_month = 31;
}

// 3. 日期进位
if (d > days_in_month) {
    d = 1;  // 或者 d -= days_in_month，但 k≤24 最多跨一天，直接设为 1 即可
    m++;
}

// 4. 月份进位
if (m > 12) {
    m = 1;
    y++;
}

cout<<y<<" "<<m<<" "<<d<<" "<<h<<" ";
}

#ifndef LUOGU_MAIN
int main()
{
    B4260 ();
    return 0;
}
#endif