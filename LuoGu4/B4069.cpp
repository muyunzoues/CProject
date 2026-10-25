#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool isWord(string s)
{
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] < s[i - 1])
        {
            return false;
        }
    }
    return true;
}

void B4069()
{
    int t;
    cin >> t;
    vector<vector<string>> ss(t);
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        vector<string> s(n);
        for (int j = 0; j < n; j++)
        {
            cin >> s[j];
        }
        ss[i] = s;
    }
    for (int i = 0; i < t; i++)
    {
        vector<string> s = ss[i];
        sort(s.begin(), s.end());
        string res;
        for (int j = 0; j < s.size(); j++)
        {
            res += s[j];
        }
        if (isWord(res))
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
}

#ifndef LUOGU_MAIN
int main()
{
    B4069();
    return 0;
}
#endif