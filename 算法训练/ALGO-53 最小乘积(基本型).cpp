#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<ll> v1(n),v2(n);
		for(int i=0;i<n;++i)cin>>v1[i];
		for(int i=0;i<n;++i)cin>>v2[i];
		sort(v1.begin(),v1.end());
		sort(v2.begin(),v2.end());
		ll res=0;
		for(int i=0;i<n;++i)res+=v1[i]*v2[n-i-1];
		cout<<res<<"\n";
	} 
	return 0;
}
