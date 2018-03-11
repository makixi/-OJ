#include<iostream>
#include<algorithm>
using namespace std;
int dp[5010],w[210],v[210];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d%d",&w[i],&v[i]);
	for(int i=1;i<=n;++i)
		for(int j=m;j>=w[i];--j)
			dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
	cout<<dp[m];
	return 0;
}
