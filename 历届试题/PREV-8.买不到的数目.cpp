#include<iostream>
using namespace std;
int a[100001];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n*m;++i)
		for(int j=0;j<n*m;++j){
			if(i*n+j*m>=100001)break;
			a[i*n+j*m]=1;
		}
	for(int i=n*m-1;i>=0;--i)
		if(!a[i]){
			cout<<i;break;
		}
	return 0;
}
