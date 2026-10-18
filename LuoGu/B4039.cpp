#include<iostream>
#include<vector>
#include <iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;

//判断是否是回文字符串
bool isPalindrome(const string& s) {
    int left = 0;
    int right = s.size() - 1;
    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}


void B4039(){
    int n;
    cin>>n;
    vector<string> ss(n);
    for(int i=0;i<n;i++){
        cin>>ss[i];
    }
    for (int i = 0; i < n; i++) {
    bool found = false;
    for (int j = 1; j < (int)ss[i].size(); j++) {   // j 从 1 开始，保证左边非空
        string left = ss[i].substr(0, j);
        string right = ss[i].substr(j, ss[i].size() - j);
        if (isPalindrome(left) && isPalindrome(right) && left.size()>1 && right.size()>1) {  // 左右两部分都必须是回文，且长度大于 1
            found = true;
            break;
        }
    }
    cout << (found ? "Yes" : "No") << endl;
}

}

#ifndef LUOGU_MAIN
int main()
{
    B4039();
    return 0;
}
#endif