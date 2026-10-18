#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;
void B4414()
{
    int m;
    cin >> m;
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int start = 2; // 0=MON, 1=TUE, 2=WED (1月1日是星期三)
    int offset = 0;
    for (int i = 1; i < m; i++)
    {
        offset += days[i];
    }
    int first = (start + offset) % 7; // 目标月1号是星期几
    cout << "MON TUE WED THU FRI SAT SUN" << endl;
    for (int i = 0; i < first; i++)
    {
        cout << "    "; // 4 个空格
    }
    for (int d = 1; d <= days[m]; d++)
    {
        if (d < 10)
        {
            cout << "  " << d << " "; // 2个空格 + 1位数字 + 1个空格 = 4字符，个位在第3位
        }
        else
        {
            cout << " " << d << " "; // 1个空格 + 2位数字 + 1个空格 = 4字符，个位在第3位
        }

        // 判断是否换行
        if ((first + d) % 7 == 0)
        {
            cout << endl;
        }
    }
}

#ifndef LUOGU_MAIN
int main()
{
    B4414();
    return 0;
}
#endif