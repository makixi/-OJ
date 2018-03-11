#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){
	return (a==0)?b:gcd(b%a,a);
}
int main(){
	ios::sync_with_stdio(false);
	ll a,b,c;
	cin>>a>>b>>c;
	ll tmp=a*b/gcd(a,b);
	cout<<tmp*c/gcd(tmp,c);
	return 0;
}
