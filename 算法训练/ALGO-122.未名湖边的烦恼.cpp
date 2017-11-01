##include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int dp[20][20];
int main() {
	int m,n;
	scanf("%d%d",&m,&n);
	dp[1][0]=1;
	for(int i=1;i<=m;++i)
		for(int j=0;j<=n&&i>=j;++j)
			if(j==0)dp[i][0]=1;
			else dp[i][j]=dp[i-1][j]+dp[i][j-1];
	cout<<dp[m][n];
	return 0;
}
