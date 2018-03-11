#include<iostream>
using namespace std;
double dp[110][10000];//选择i个数字，和为j 
int main(){
	int n,a,b,x;
	scanf("%d%d%d%d",&n,&a,&b,&x);
	for(int i=a;i<=b;++i)dp[1][i]=1.0/(b-a+1);
	for(int i=2;i<=n;++i)
		for(int j=a;j<=b;++j)
			for(int k=1;k<=x;++k)
				dp[i][k]+=dp[i-1][k-j]*1.0/(b-a+1);  
	printf("%.4lf",dp[n][x]);
	return 0;
}
