#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std; 
const int maxn=200000+10;
const int inf=0x3f3f3f3f;
bool vis[maxn];
int dis[maxn];
struct Edge{
	int to;
	int w;
	int nextEdge;
}edge[maxn];
int head[maxn];
int tot=0;
void add(int u,int v,int l){
	edge[tot].to=v;
	edge[tot].nextEdge=head[u];
	edge[tot].w=l;
	head[u]=tot++;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	memset(head,-1,sizeof(head));
	for(int i=0;i<m;++i){
		int u,v,l;
		scanf("%d%d%d",&u,&v,&l);
		add(u,v,l);
	}
	memset(dis,inf,sizeof(dis));
	queue<int> q;
	q.push(1);
	vis[1]=true;
	dis[1]=0;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=head[u];i!=-1;i=edge[i].nextEdge){
			int v=edge[i].to;
			if(dis[v]>dis[u]+edge[i].w){
				dis[v]=dis[u]+edge[i].w;
				if(!vis[v]){
					vis[v]=true;
					q.push(v);
				}
			}
		}
	}
	for(int i=2;i<=n;++i)cout<<dis[i]<<"\n";
	return 0;
}
