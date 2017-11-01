#include<iostream>
#include<cstring>
using namespace std;
const int mod = 1000000007;
int dp[110][110];//长度为i，最后一位为j 
int main(){
    int k,l;
    scanf("%d%d",&k,&l);
    memset(dp,0,sizeof(dp));
    for(int i=0; i<k; i++)dp[1][i] = 1;
    for(int i=2; i<=l; i++)
        for(int j=0; j<k; j++)
            for(int f=0; f<k; f++)
                if(f+1 != j && f-1!=j){
                    dp[i][j] += dp[i-1][f];
                    dp[i][j] %= mod;
                }
    int sum = 0;
    for(int i=1; i<k; i++){
        sum += dp[l][i];
        sum %= mod;
    }
    printf("%d\n",sum);
    return 0;
}

