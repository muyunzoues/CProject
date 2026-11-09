#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

const int MAXA = 100000;

// 检查一个数是否只包含质因数2和5
bool check(int x){
    while(x % 2 == 0) x /= 2;
    while(x % 5 == 0) x /= 5;
    return x == 1;
}
//只有质因数2和5的数的相反数才是有限不循环小数
void P15798()
{
    int l,r;
    cin >> l >> r;
    int count = 0;
    for(int i = l; i <= r; i++){
        if(check(i)) count++;
    }
    cout << count << endl;
}

#ifndef LUOGU_MAIN
int main()
{
    P15798();
    return 0;
}
#endif