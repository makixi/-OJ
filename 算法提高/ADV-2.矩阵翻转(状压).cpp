#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int x[33][33],ans,N;
const int inf=0x3f3f3f3f;
void fun1(int n){
    int lin=0,aa,bb;
    for(int j=0;j<N;j++)lin+=x[n-1][j];
    for(int i=0;i<n-1;i++){
        aa=-inf;
        bb=x[i][n-1]+x[i+n][n-1];
        for(int j=0;j<n-1;j++)bb+=abs(x[i][j]+x[i+n][j]+x[i][j+n]+x[i+n][j+n]);
        aa=max(aa,bb);
        bb=-x[i][n-1]-x[i+n][n-1];
        for(int j=0;j<n-1;j++)bb+=abs(-x[i][j]-x[i+n][j]+x[i][j+n]+x[i+n][j+n]);
        aa=max(aa,bb);
        lin+=aa;
    }
    ans=max(ans,lin);
}
void fun(int n){
    int i,j,k;
    for(k=0;k<(1<<n-1);k++){
        for(i=0;i<n-1;i++)
            if(k&(1<<i))
                for(j=0;j<n;j++){
                    x[j][i]*=-1;
                    x[j][i+n]*=-1;
                }
        fun1(n);
        for(i=0;i<n-1;i++)
            if(k&(1<<i))
                for(j=0;j<n;j++){
                    x[j][i]*=-1;
                    x[j][i+n]*=-1;
                }
    }
}
int main(){
    int i,j,k;
    scanf("%d",&N);
    for(i=0;i<N;i++)for(j=0;j<N;j++)scanf("%d",&x[i][j]);
    k=(N+1)/2;
    ans=-inf;
    fun(k);
    printf("%d\n",ans);
    return 0;
}
