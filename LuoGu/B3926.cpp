#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int n;cin>>n;
	while(n--){
		int a;
		string b,c;
		cin>>a>>b>>c>>c>>c;
		if(b.length()==1||c.length()==1){//* 换 m* 或 k* 换 *，都要 *1000
			cout<<a<<" "<<b<<" = "<<a*1000<<" "<<c<<endl;
		}else{//k* 换 m*，要 *1000000
			cout<<a<<" "<<b<<" = "<<a*1000000<<" "<<c<<endl;
		}
	} 
	return 0;
}
