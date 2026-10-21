#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool isSimilar(string s1, string s2)
{
    int len1 = s1.length(), len2 = s2.length();
    if (len1 > len2 + 1 || len2 > len1 + 1)
    {
        return false;
    }
    else if (len1 == len2)
    {
        int i = 0;
        int diff = 0; // 统计需要变化的数目
        while (i < len1)
        {
            if (s1[i] != s2[i])
            {
                diff++;
            }
            i++;
        }
        if (diff > 1)
        {
            return false;
        }
    }
    else if (len1 == len2 + 1)
    {
        int i = 0, j = 0;
        int diff = 0; // 统计需要变化的数目
        while (i < len1 && j < len2)
        {
            if (s1[i] != s2[j])
            {
                diff++;
                i++;
            }
            else
            {
                i++;
                j++;
            }
        }
        if (diff > 1)
        {
            return false;
        }
    }
    else if (len2 == len1 + 1)
    {
        int i = 0, j = 0;
        int diff = 0; // 统计需要变化的数目
        while (i < len1 && j < len2)
        {
            if (s1[i] != s2[j])
            {
                diff++;
                j++;
            }
            else
            {
                i++;
                j++;
            }
        }
        if (diff > 1)
        {
            return false;
        }
    }
    return true;
}

void B3958()
{
    int n;
    cin >> n;
    vector<vector<string>> ss(n, vector<string>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> ss[i][0] >> ss[i][1];
    }
    for (int i = 0; i < n; i++)
    {
        if (isSimilar(ss[i][0], ss[i][1]))
        {
            cout << "similar" << endl;
        }
        else
        {
            cout << "not similar" << endl;
        }
    }
}

#ifndef LUOGU_MAIN
int main()
{
    B3958();
    return 0;
}
#endif