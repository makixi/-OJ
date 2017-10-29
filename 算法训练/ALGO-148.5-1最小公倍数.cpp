#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){
	if(a==0)return b;
	return gcd(b%a,a);
}
int main(){
    ll a,b;cin>>a>>b;
    cout<<(a*b)/gcd(a,b);
	return 0;
}
