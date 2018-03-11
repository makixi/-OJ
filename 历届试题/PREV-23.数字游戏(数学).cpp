#include<iostream>
using namespace std;
typedef long long ll;
ll sum=0;
ll n,k,t;
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>k>>t;
	ll curr=1;
	for(int i=0;i<t;++i){
		sum+=curr;
		curr+=(n+1+2*i*n)*n/2;
		while(curr>=k)curr%=k;
	}
	cout<<sum;
	return 0;
}
