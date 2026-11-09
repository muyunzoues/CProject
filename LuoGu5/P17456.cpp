#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;

const double EPS = 1e-9;

void P17456()
{
    double n, t;
    cin >> n >> t;

    vector<vector<double>> numsP; // 偏甜 {v, s}
    vector<vector<double>> numsN; // 偏淡 {v, s}
    double ans = 0;

    for (int i = 0; i < n; i++)
    {
        double v, s;
        cin >> v >> s;
        if (fabs(s - t) < EPS)
        {
            ans += v; // 完美匹配，直接全用
        }
        else if (s > t)
        {
            numsP.push_back({v, s});
        }
        else
        {
            numsN.push_back({v, s});
        }
    }

    double P = 0, N = 0;
    double sumP = 0, sumN = 0;
    for (auto &x : numsP)
    {
        P += x[0] * (x[1] - t);
        sumP += x[0];
    }
    for (auto &x : numsN)
    {
        N += x[0] * (t - x[1]);
        sumN += x[0];
    }

    // 只有一边有偏差，或两边都没有偏差
    if (fabs(P) < EPS || fabs(N) < EPS)
    {
        cout << fixed << setprecision(3) << ans << endl;
        return;
    }

    // 正负偏差刚好相等，全部用光
    if (fabs(P - N) < EPS)
    {
        cout << fixed << setprecision(3) << ans + sumP + sumN << endl;
        return;
    }

    if (P > N)
    {
        // 偏淡组全用
        ans += sumN;
        double need = N; // 需要从偏甜组凑出的正偏差

        // 按每升偏差从小到大排序
        sort(numsP.begin(), numsP.end(), [t](const vector<double> &a, const vector<double> &b)
             { return (a[1] - t) < (b[1] - t); });

        for (auto &x : numsP)
        {
            double diff = x[1] - t;
            double totalDiff = x[0] * diff;
            if (totalDiff <= need)
            {
                ans += x[0]; // 全用
                need -= totalDiff;
            }
            else
            {
                ans += need / diff; // 只用一部分
                break;
            }
        }
    }
    else
    {
        // 偏甜组全用
        ans += sumP;
        double need = P; // 需要从偏淡组凑出的负偏差

        // 按每升偏差从小到大排序
        sort(numsN.begin(), numsN.end(), [t](const vector<double> &a, const vector<double> &b)
             { return (t - a[1]) < (t - b[1]); });

        for (auto &x : numsN)
        {
            double diff = t - x[1];
            double totalDiff = x[0] * diff;
            if (totalDiff <= need)
            {
                ans += x[0];
                need -= totalDiff;
            }
            else
            {
                ans += need / diff;
                break;
            }
        }
    }

    cout << fixed << setprecision(3) << ans << endl;
}

#ifndef LUOGU_MAIN
int main()
{
    P17456();
    return 0;
}
#endif