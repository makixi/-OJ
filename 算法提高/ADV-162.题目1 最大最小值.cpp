#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
int main(){
	int n,maxn=-inf,minn=inf;
	scanf("%d",&n);
	while(n--){
		int a;
		scanf("%d",&a);
		maxn=max(maxn,a);
		minn=min(minn,a);
	}
	cout<<maxn<<" "<<minn;
	return 0;
}
