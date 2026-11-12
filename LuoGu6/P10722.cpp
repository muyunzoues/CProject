#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 200005;
vector<int> children[MAXN]; // 每个节点的孩子列表
int tag[MAXN];              // tag[u] = 1 表示 u 被直接操作了奇数次
int initColor[MAXN];        // 初始颜色
int finalColor[MAXN];       // 最终颜色

// dfs(u, cur)：cur 是从根到 u 的父节点路径上累计的翻转次数（模 2）
void dfs(int u, int cur)
{
    cur ^= tag[u];                      // 加上 u 自己的操作
    finalColor[u] = initColor[u] ^ cur; // 最终颜色 = 初始颜色翻转 cur 次
    for (int v : children[u])
    {
        dfs(v, cur); // 把孩子也带上同样的累计翻转
    }
}

void P10722()
{
    int n;
    cin >> n;

    // 读入每个节点 i（2~n）的父节点
    for (int i = 2; i <= n; i++)
    {
        int p;
        cin >> p;
        children[p].push_back(i);
    }

    // 读入初始颜色字符串，节点 1~n 对应 s[0]~s[n-1]
    string s;
    cin >> s;
    for (int i = 1; i <= n; i++)
    {
        initColor[i] = s[i - 1] - '0';
    }

    // 读入操作
    int q;
    cin >> q;
    while (q--)
    {
        int a;
        cin >> a;
        tag[a] ^= 1; // 奇偶性翻转
    }

    // 从根节点 1 开始 DFS，初始累计翻转为 0
    dfs(1, 0);

    // 按节点编号 1~n 输出最终颜色
    for (int i = 1; i <= n; i++)
    {
        cout << finalColor[i];
    }
    cout << endl;
}

#ifndef LUOGU_MAIN
int main()
{
    P10722();
    return 0;
}
#endif