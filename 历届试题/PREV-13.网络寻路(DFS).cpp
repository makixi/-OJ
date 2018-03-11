#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<cstring>
#include<cmath>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=10000+1;
vector<int> e[maxn];
bool vis[maxn];
int n,res=0,st;
void dfs(int fa,int u,int dep){
	if(u==st&&dep<2)return;
	if(dep==3){
		++res;
		return;
	}
	for(int i=0;i<e[u].size();++i){
		int v=e[u][i];
		if(!vis[v]){
			vis[v]=true;
			dfs(u,v,dep+1);
			vis[v]=false;
		}
		if(v==st&&dep==2&&v!=fa){
			++res;continue;
		}
	}
}
int main(){
	int m;
	scanf("%d%d",&n,&m);
	while(m--){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	for(st=1;st<=n;++st){//start
		vis[st]=true;
		for(int j=0;j<e[st].size();++j){
			int v=e[st][j];
			vis[v]=true;
			dfs(st,v,1);
			vis[v]=false;
		}
		vis[st]=false;
	}
	cout<<res;
	return 0;
}
