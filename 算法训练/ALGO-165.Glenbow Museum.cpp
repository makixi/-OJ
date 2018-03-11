#include <iostream>
using namespace std;
typedef long long ll;
ll C(int n,int m) {  
    ll s=1,t=1;  
    if (m>n-m) m=n-m;  
    for (int i=1;i<=m;i++) {  
        s*=(ll)(n-i+1);
		t*=(ll)i;  
    }  
    return s/t;  
}  
int main()  {  
    int l,ca=0;  
    while (scanf("%d", &l)&&l) {  
        if ((l<4)||(l&1)) { printf("Case %d: 0\n", ++ca);continue ; }  
        if (l==4) { printf("Case %d: 1\n", ++ca);continue ; }  
        printf("Case %d: %lld\n", ++ca, 2*C((l-4)/2+3,(l-4)/2-1)+C((l-4)/2+3,(l-4)/2));  
    }  
    return 0;  
}  
