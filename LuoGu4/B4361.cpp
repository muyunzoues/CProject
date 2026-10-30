#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

// 交换的次数正好等于逆序对的数量
void B4361()
{
    int n;
    cin >> n;
    vector<int> h(n);
    vector<int> w(n);
    for (int i = 0; i < n; i++)
    {
        cin >> h[i] >> w[i];
    }

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (h[i] < h[j] || (h[i] == h[j] && w[i] < w[j]))
            {
                res++; // 统计逆序对的数目
            }
        }
    }
    cout << res << endl;
}

#ifndef LUOGU_MAIN
int main()
{
    B4361();
    return 0;
}
#endif