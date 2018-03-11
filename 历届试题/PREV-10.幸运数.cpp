
#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
int a[1000009];
void dfs(int s){
	int cnt=s;
	if(a[s]>m)return;
	for(int i=s;i<=m;i++)if(i%a[s])a[cnt++]=a[i];
	dfs(s+1);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)a[i]=2*i-1;
	dfs(1);
	int ans=0,i=1;
	while(a[i]<m)if(a[i++]>n)ans++;
	printf("%d\n",ans);
	return 0;
}
