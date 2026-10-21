#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_map>
using namespace std;

void B3927()
{
    int n;
    cin >> n;
    unordered_map<string, string> map;
    for (int i = 0; i < n; i++)
    {
        string a, b;
        cin >> a >> b;
        map[a] = b;
    }
    string ss;
    cin >> ss;
    ss += '.'; // 末尾加标点，保证最后一个单词能被处理
    int i = 0, j = 0;
    string res;
    while (j < ss.length())
    {
        while (j < ss.length() && ss[j] >= 'a' && ss[j] <= 'z')
        {
            j++;
        }
        string temp = ss.substr(i, j - i);
        if (!temp.empty())
        { // 只有非空单词才翻译
            auto it = map.find(temp);
            if (it != map.end())
            {
                res += it->second;
            }
            else
            {
                res += "UNK";
            }
        }
        while (j < ss.length() && ss[j] < 'a' || ss[j] > 'z')
        {
            res += ss[j];
            j++;
        }
        i = j;
    }
    // 最后去掉人为加的那个 '.'
    res.pop_back();
    cout << res << endl;
}

#ifndef LUOGU_MAIN
int main()
{
    B3927();
    return 0;
}
#endif