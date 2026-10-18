#include<iostream>
#include<vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;
void B4413(){
    int n;
    cin >> n;
    priority_queue<int> maxHeap;                    // 最大堆
    priority_queue<int, vector<int>, greater<int>> minHeap;  // 最小堆（非零）
    vector<int> nums(n);
    //最值问题可用最大堆与最小堆求解
    for(int i=0;i<n;i++){
        cin>>nums[i];
        if(nums[i]>0){
            maxHeap.push(nums[i]);
            minHeap.push(nums[i]);
        }
    }
    long long res=0;
    while (!maxHeap.empty()) {
    int Max = maxHeap.top(); maxHeap.pop();
    int Min = minHeap.top();   // 不弹出！
    
    int newVal = Max - Min;
    res++;
    
    if (newVal > 0) {
        maxHeap.push(newVal);
        minHeap.push(newVal);
    } else {
        // Max 变成 0，消失
        // 如果 Max == Min，说明这个最小值也消失了，需要从 minHeap 弹出
        if (Max == Min) {
            minHeap.pop();
        }
    }
}
    cout<<res<<endl;
}

#ifndef LUOGU_MAIN
int main()
{
    B4413();
    return 0;
}
#endif