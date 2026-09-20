#include<iostream>
#include<vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;

vector<int> getNum(int n) {
    vector<int> res(3, 0);   // 固定 3 位，初始全 0
    int idx = 0;
    while (n > 0) {
        res[idx++] = n % 10;
        n /= 10;
    }
    return res;
}
//计算n的m次方
int getSum(int n,int m){
   int sum=1;
   for(int i=1;i<=m;i++){
       sum*=n;
   }
   return sum;
}
// nums 已经按从小到大排序，nums[0] 最小，nums[2] 最大
int getMax(vector<int> nums) {
    return nums[2] * 100 + nums[1] * 10 + nums[0];
}

int getMin(vector<int> nums) {
    return nums[0] * 100 + nums[1] * 10 + nums[2];
}

void B3866(){
    int n;
    cin>>n;
    vector<int> nums=getNum(n);
    sort(nums.begin(),nums.end());
    int res=0;
    while(true){
        int maxNum = getMax(nums);
        int minNum = getMin(nums);
        int diff = maxNum - minNum;
        res++;                    // 这次操作完成，计数 +1
        if (diff == 495) {
            cout << res << endl;
            break;
        }
        nums = getNum(diff);
        sort(nums.begin(), nums.end());
    }
}

#ifndef LUOGU_MAIN
int main()
{
    B3866();
    return 0;
}
#endif