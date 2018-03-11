#include<iostream>
using namespace std;
typedef long long ll;
const int maxn=1010;
const ll mod=1000000007;
ll a[maxn]={0},b[maxn]={0};
int main() {
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	b[1]=1;
	for(int i=2;i<=n;++i)b[i]=(b[i-1]*2%mod);
	a[1]=1,a[2]=6;
	for(int i=3;i<=n;++i)a[i]=(2*a[i-1]+b[i]+4*a[i-2])%mod;
	ll sum=4*a[n];
	for(int i=2;i<n;++i){
		sum+=((8*b[n-i]*a[i-1])%mod+(8*a[n-i]*b[i-1])%mod)%mod;  
        sum%=mod; 
	}
	if(n==1)sum=2;
	cout<<sum;
	return 0;
}
