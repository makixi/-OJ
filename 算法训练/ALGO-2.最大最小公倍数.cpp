#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
	ll n,res;cin>>n;
	if(n<=2)res=n;
	else if(n&1)res=n*(n-1)*(n-2);
	else if(n%3==0)res=(n-1)*(n-2)*(n-3);
	else res=n*(n-1)*(n-3);
	cout<<res;
	return 0;
} 
