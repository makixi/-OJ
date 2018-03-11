#include<iostream>
using namespace std;
#define max(a,b) (a>=b)?a:b		//³¬Ê±Á¼Ò© 
const int inf=0x3f3f3f3f;
const int maxn=510;
int n,m,res=-inf;
int maze[maxn][maxn];
int dp[maxn];
int solve() {
	int sum = 0,maxsum=dp[0];
	for (int i = 0; i < m; ++i) {
		sum += dp[i];
		sum = max(sum, dp[i]);
		maxsum = max(maxsum, sum);
	}
	return maxsum;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)scanf("%d",&maze[i][j]);
	for(int be=0;be<n;++be){
		for(int en=be;en<n;++en){
			for(int k=0;k<m;++k)
				dp[k]+=maze[en][k];
			res=max(res,solve());
		}
		for(int k=0;k<m;++k)dp[k]=0;
	}
	cout<<res;
	return 0;
} 
