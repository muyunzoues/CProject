#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

void B4578()
{
    string ss;
    getline(cin, ss);
    vector<string> res;
    int need = 1;
    int i = 0, j = 0;
    while (j < ss.length())
    {
        while (j < ss.length() && ss[j] != ' ')
        {
            j++;
        }
        // res.push_back(ss.substr(i,j-i));
        int run = 0;
        int temp = j;
        while (ss[temp] == ' ' && run < need)
        {
            run++;
            temp++;
        }
        if (run >= need)
        {
            res.push_back(ss.substr(i, j - i));
            i = temp;
            j = temp;
            need++;
        }
        else
        {
            j = temp;
        }
    }
    // 处理最后一个单词（后面空格不足或没有空格的情况）
    if (i < ss.length())
    {
        res.push_back(ss.substr(i));
    }
    for (string s : res)
    {
        cout << s << endl;
    }
}

#ifndef LUOGU_MAIN
int main()
{
    B4578();
    return 0;
}
#endif