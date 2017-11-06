#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;

int main(){
	int n,maxn,maxindex,tmp;
	scanf("%d",&n);
	scanf("%d",&tmp);
	maxn=tmp,maxindex=0;
	for(int i=1;i<n;++i){
		scanf("%d",&tmp);
		if(tmp>maxn){
			maxn=tmp;
			maxindex=i;
		}
	}
	cout<<maxn<<" "<<maxindex;
	return 0;
}
