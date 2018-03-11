#include <iostream>
#include <memory.h>
#define MAXN 1100
#define MOD 100000007
using namespace std;
int F[2][MAXN*MAXN];//前i个元素组成和为j的序列的方案数    前状态覆盖后状态    
int e = 0;
long long n,s,a,b;
int cnt = 0;
void DP(){
    F[e][0]=1;
    for(int i=1;i<n;i++){
        e=1-e;
        for(int j=0;j<=i*(i+1)/2;j++)
            if(i>j) F[e][j]=F[1-e][j];
            else F[e][j]=(F[1-e][j]+F[1-e][j-i])%MOD;
    }
}
int main(){
	ios::sync_with_stdio(false);
    cin>>n>>s>>a>>b;
    long long i,t;
    DP();
    for(i=0; i<=n*(n-1)/2; i++){//a和b的总数为n*(n-1)/2
        t = s - i*a + (n*(n-1)/2-i)*b;
        if(t%n==0)cnt = (cnt+F[e][i])%MOD;
    }
    cout<<cnt;
    return 0;
}
