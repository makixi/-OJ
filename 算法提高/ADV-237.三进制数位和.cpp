#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[6];
bool is_prime(int n){
	if(n<=1)return false;
	for(int i=2;i*i<=n;++i)
		if(n%i==0)return false;
	return true;
}
int main(){
	int res=0; 
	int l,r;
	scanf("%d%d",&l,&r);
	for(a[0]=0;a[0]<=2;++a[0])
		for(a[1]=0;a[1]<=2;++a[1])
			for(a[2]=0;a[2]<=2;++a[2])
				for(a[3]=0;a[3]<=2;++a[3])
					for(a[4]=0;a[4]<=2;++a[4])
						for(a[5]=0;a[5]<=2;++a[5]){
							int tmp=a[0]+a[1]+a[2]+a[3]+a[4]+a[5];
							if(is_prime(tmp)||(tmp>=l&&tmp<=r))++res;
						}
	cout<<res;
	return 0;
}
