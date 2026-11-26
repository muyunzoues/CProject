#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <numeric>
#include <stack>
using namespace std;

// 通过栈化简操作，当上次操作是LR，下次操作是U时，两次操作可以抵消。
void P11375()
{
    long long n, s;
    cin >> n >> s;
    string ss;
    cin >> ss;
    vector<char> stk;
    for (char c : ss)
    {
        if (c == 'U')
        {
            if (!stk.empty() && (stk.back() == 'L' || stk.back() == 'R'))
            {
                stk.pop_back();
            }
            else
            {
                stk.push_back('U');
            }
        }
        else
        {
            stk.push_back(c);
        }
    }
    // 用化简后的栈模拟，此时不会发生溢出
    for (char c : stk)
    {
        if (c == 'U')
        {
            if (s > 1)
                s /= 2; // 根节点 1 的父节点还是 1，题目说“否则不移动”
        }
        else if (c == 'L')
        {
            s *= 2;
        }
        else if (c == 'R')
        {
            s = s * 2 + 1;
        }
    }
    cout << s << endl;
}

#ifndef LUOGU_MAIN
int main()
{
    P11375();
    return 0;
}
#endif