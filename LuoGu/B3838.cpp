#include<iostream>
#include<vector>
using namespace std;
void B3838(){
    vector<int> nums;
    int n;
    // 循环读取，直到输入结束
    while (cin >> n) {
        nums.push_back(n);
    }
    int res=(nums[2]-nums[0])*60+nums[3]-nums[1];
    cout << res << endl;
}

#ifndef LUOGU_MAIN
int main()
{
    B3838();
    return 0;
}
#endif