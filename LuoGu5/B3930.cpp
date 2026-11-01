#include <iostream>
#include <vector>
using namespace std;

void B3930()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int ans = 0;
    // 从最高位 30 开始尝试到第 0 位
    for (int i = 30; i >= 0; i--)
    {
        int target = ans | (1 << i);
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            // 检查 a[j] 是否包含 target 的所有 1 位
            if ((a[j] & target) == target)
            {
                cnt++;
            }
        }
        // 如果至少有两个数满足，这一位可以设为 1
        if (cnt >= 2)
        {
            ans = target;
        }
    }
    cout << ans << endl;
}

#ifndef LUOGU_MAIN
int main()
{
    B3930();
    return 0;
}
#endif