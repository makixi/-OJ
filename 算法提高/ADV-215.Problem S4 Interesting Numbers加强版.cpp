#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
ll q_mod(ll a,ll b){
    ll ans1=1;
    ll tmp=a;
    while(b>0){
        if(b&1) ans1 = ans1 * tmp % mod;
        b>>=1; 
        tmp = tmp * tmp % mod;
    }
    return ans1;
}
int main(){
    ll ans=0,tmp=0;
    ll n;
    cin>>n;
    n--;
    ans = (n % mod) * (n % mod);
    ans = ((ans - 3 * n) % mod + mod) %mod;
    tmp = q_mod(2,n-2);
    ans = ans * tmp % mod;
    ans = (ans + n) % mod;
    cout<<ans<<endl;
    return 0;
}
