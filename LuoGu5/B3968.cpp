#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_map>
using namespace std;

class stu
{
private:
    int C;
    int M;
    int E;
    int id;
    int rank;

public:
    stu(const int C1, const int M1, const int E1, const int id1)
    {
        C = C1;
        M = M1;
        E = E1;
        id = id1;
        rank = 0;
    }
    int sum() const
    {
        return C + M + E;
    }
    int sumCM() const
    {
        return C + M;
    }
    int maxCM() const
    {
        return max(C, M);
    }
    int getId() const
    {
        return id;
    }
    int getRank() const
    {
        return rank;
    }
    void setRank(int r)
    {
        rank = r;
    }
};

bool cmp(const stu &a, const stu &b)
{
    if (a.sum() != b.sum())
    {
        return a.sum() > b.sum();
    }
    if (a.sumCM() != b.sumCM())
    {
        return a.sumCM() > b.sumCM();
    }
    if (a.maxCM() != b.maxCM())
    {
        return a.maxCM() > b.maxCM();
    }
    return false;
}

// 判断两人是否并列（三项指标都相同）
bool sameRank(const stu &a, const stu &b)
{
    return a.sum() == b.sum() && a.sumCM() == b.sumCM() && a.maxCM() == b.maxCM();
}

void B3968()
{
    int n;
    cin >> n;
    vector<stu> stus;//没有提供无参默认构造函数，只能通过emplace_back或push_back分配集合元素
    for (int i = 0; i < n; i++)
    {
        int C1, M1, E1;
        cin >> C1 >> M1 >> E1;
        stu s(C1, M1, E1, i);
        stus.push_back(s);
    }
    // 按成绩排序
    sort(stus.begin(), stus.end(), cmp);
    // 计算排名（处理并列）
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            stus[i].setRank(1);
        }
        else
        {
            if (sameRank(stus[i], stus[i - 1]))
            {
                stus[i].setRank(stus[i - 1].getRank()); // 并列，排名相同
            }
            else
            {
                stus[i].setRank(i + 1); // 不并列，排名 = 位置 + 1
            }
        }
    }
    // 按原始 id 排序，恢复输入顺序
    sort(stus.begin(), stus.end(), [](const stu &a, const stu &b)
         { return a.getId() < b.getId(); });
    // 按输入顺序输出排名
    for (int i = 0; i < n; i++) {
        cout << stus[i].getRank() << endl;
    }
}

#ifndef LUOGU_MAIN
int main()
{
    B3968();
    return 0;
}
#endif