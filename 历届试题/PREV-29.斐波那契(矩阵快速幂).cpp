#include <stdio.h>
long long p;
typedef struct matrix2_2{long long x[2][2];}mat;
mat A={1,1,1,0};
mat E={1,0,0,1};
long long mul(long long a,long long b,long long mod){
    long long x=0;
    if(a<b){
        a=a^b;
        b=a^b;
        a=a^b;
    }
    while(b){
        if(b%2) x=(x+a)%mod;
        a=(a*2)%mod;
        b=b/2;
    }
    return x;
}
mat mat_multi(mat a,mat b){
    mat c;
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++){
            c.x[i][j]=0;    
            for(int k=0;k<2;k++){
                c.x[i][j]+=mul(a.x[i][k],b.x[k][j],p);
                c.x[i][j]%=p;
            }
        }
    return c;
}
mat mat_pow(mat X,long long n){
    mat a=E,b=X;
    while(n){
        if(n%2){
            a=mat_multi(a,b);
            n--;
        }
        b=mat_multi(b,b);
        n=n/2;
    }
    return a;
}
//¼ÆËãf(n)%p
long long dream(long long n){
    mat a=mat_pow(A,n);
    return a.x[1][0];
}
//¼ÆËãf(m-1)*f(n%m)%f(m)
long long real(long long n,long long m){
    long long a=n%m;
    if(a%2) return dream(m-a);
    return((dream(m)-dream(m-a))%p+p)%p;
}
long long solve(long long n,long long m){
    long long t1=n/m;
    if(m%2){
        if(!t1%2&&!t1%4) return dream(n%m);
        if(!t1%2&&t1%4) return ((dream(m)-dream(n%m))%p+p)%p;
        if(t1%2&&!t1%4) return real(n,m);
        if(t1%2&&t1%4) return ((dream(m)-real(n,m))%p+p)%p;
    }
    else{
        if(t1%2) return real(n,m);
        else return dream(n%m);
    }
}
long long get_value(long long n,long long m){
    n+=2;
    long long a=solve(n,m);
    if(!a)return dream(m)-1;
    return a-1;
}
int main(){
    long long n,m;
    scanf("%I64d%I64d%I64d",&n,&m,&p);
    printf("%I64d",get_value(n,m));
    return 0;
}
