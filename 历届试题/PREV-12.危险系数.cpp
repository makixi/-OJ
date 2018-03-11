#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=1010;
typedef long long ll;
vector<int> e[maxn];
bool vis[maxn];
int n,m,s,t,broken;
bool flag;
void dfs(int u){
	if(flag)return;
	if(u==t){
		flag=true;
		return;
	}
	for(int i=0;i<e[u].size();++i){
		int v=e[u][i];
		if(!vis[v]&&v!=broken&&!flag){
			vis[v]=true;
			dfs(v);
			vis[v]=false;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
    scanf("%d%d",&n,&m);
    while(m--){
    	int a,b;
    	scanf("%d%d",&a,&b);
    	e[a].push_back(b);
    	e[b].push_back(a);
	}
	scanf("%d%d",&s,&t);
	flag=false;
	vis[s]=true;
	dfs(s);
	vis[s]=false;
	if(!flag){
		cout<<-1;
		return 0;
	}
	int res=0;
	for(broken=1;broken<=n;++broken){
		if(broken==s||broken==t)continue;
		flag=false;
		vis[s]=true;
		dfs(s);
		vis[s]=false;
		if(!flag)++res;
	}
	cout<<res;
    return 0;
}
