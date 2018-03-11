#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=25000+5;
int T,R,P,S;//城镇T  道路R  航路T 
int tot=0;
int dis[maxn];
bool vis[maxn];//点是否在队列中
int in_sum[maxn];//点入队列的次数 
int head[maxn];
struct edge{int to,w,nex;}v[200000]; //这里道路的条数最大值不止maxn  
void add(int x,int y,int w){
	v[tot].to=y;
	v[tot].w=w;
	v[tot].nex=head[x];
	head[x]=tot++;
}
int main(){
	scanf("%d%d%d%d",&T,&R,&P,&S);
	for(int i=0;i<=T;++i)head[i]=-1,dis[i]=inf;
	while(R--){
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		add(x,y,w);
		add(y,x,w);
	}
	while(P--){
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		add(x,y,w);
	}
	dis[S]=0;
	vis[S]=true;
	in_sum[S]++;
	deque<int> q;
	q.push_back(S);
	while(!q.empty()){
		int u=q.front();q.pop_front();
		vis[u]=false;
		for(int i=head[u];i!=-1;i=v[i].nex){
			int to=v[i].to;
			if(dis[u]!=inf&&dis[to]>dis[u]+v[i].w){
				dis[to]=dis[u]+v[i].w;
				if(!vis[to]){
					vis[to]=true;
					if(!q.empty()){
						if (dis[to]>dis[q.front()])q.push_back(to);
						else q.push_front(to);
					}else q.push_back(to);
				}
			}
		}
	}
	for(int i=1;i<=T;++i)
		if(dis[i]==inf)cout<<"NO PATH\n";
		else cout<<dis[i]<<"\n";
	return 0;
} 
