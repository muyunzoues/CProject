#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <numeric>
using namespace std;
const int MAXN = 300005;
int a[MAXN], tmp[MAXN];
long long ans = 0;

void mergeSort(int l, int r)
{
    if (l >= r)
        return;
    int mid = l + (r - l) / 2;
    mergeSort(l, mid);
    mergeSort(mid + 1, r);
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r)
    {
        if (a[i] < a[j])
        { // 左 < 右，左段剩余元素都 < a[j]
            ans += (mid - i + 1);
            tmp[k++] = a[j++];
        }
        else
        {
            tmp[k++] = a[i++];
        }
    }
    while (i <= mid)
        tmp[k++] = a[i++];
    while (j <= r)
        tmp[k++] = a[j++];
    for (int p = l; p <= r; p++)
        a[p] = tmp[p];
}

void B3874()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> a[i];
    mergeSort(0, N - 1);
    cout << ans << endl;
}

#ifndef LUOGU_MAIN
int main()
{
    B3874();
    return 0;
}
#endif