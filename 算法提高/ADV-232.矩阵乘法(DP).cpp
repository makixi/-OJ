
#include<cstdio>
#include<math.h>
#include<cstring>
#include<climits>
#include<string>
#include<queue>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<climits>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<algorithm>
using namespace std;
#define rep(i,j,k)for(i=j;i<k;i++)
#define per(i,j,k)for(i=j;i>k;i--)
#define MS(x,y)memset(x,y,sizeof(x))
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define ll long long
#define abs(x) (x>0?x:-x)
const int INF=0x7ffffff;
const int SIZE=1000+10;
const ll MAX=1e18;
ll d[SIZE][SIZE];
ll m[SIZE];
int i,j,k,n;
ll matrix_DP(int n){
    ll sum;
    MS(d,0);
    for(int len=2;len<=n;len++)
        for(int i=1,j=len;j<=n;i++,j++){
            ll minx=MAX;
            for(int k=i;k<j;k++){
                sum=d[i][k]+d[k+1][j]+m[i-1]*m[k]*m[j];
                if(sum<minx)minx=sum;
            }
            d[i][j]=minx;
        }
    return d[1][n];
}
int main(){
    while(~scanf("%d",&n)){
        for(i=0;i<=n;i++)scanf("%lld",&m[i]);
        printf("%lld\n",matrix_DP(n));
    }
    return 0;
}
