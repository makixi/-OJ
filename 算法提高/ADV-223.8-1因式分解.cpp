#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;
int main() {
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	bool flag=false;
	for(int i=2;i<=n;++i){
		if(n==1)break;
		while(n%i==0){
			if(flag)cout<<"*";
			flag=true;
			cout<<i;
			n/=i;
		}
	}
	return 0;
}
