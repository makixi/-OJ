#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define mod 50000 
using namespace std;
bool prime[100001];
int main(){
	int res=1;
	int n,in;
	scanf("%d",&n);
	memset(prime,true,sizeof(prime));
	prime[0]=prime[1]=false;
	for(int i=2;i<=100000&&n;++i){
		if(!prime[i])continue;
		res=(res*i)%mod;
		n--;
		for(int j=i*2;j<=100000;j+=i)prime[j]=false;
	}
	cout<<res;
	return 0;
}
