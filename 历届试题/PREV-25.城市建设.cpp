#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define MAXN 10005 
#define MAXM 100005
struct node{
	int u,v,w; 
}edge[MAXM+MAXN];  
int fa[MAXN];  
bool cmp(node a,node b){return a.w<b.w; }
int find(int x){
	if(x==fa[x]) return x; 
	return fa[x]=find(fa[x]);    
}
int route(int n,int m){
	for (int i=0;i<=n;i++)fa[i]=i; 
	sort(edge,edge+m,cmp);     
	int sum=0;  
	for (int i=0;i<m;i++){ 
		int fu=find(edge[i].u);  
		int fv=find(edge[i].v);  
		int w=edge[i].w; 
		if (fu!=fv||w<0){
			sum+=w;   
			fa[fu]=fv; 
		}
	} 
	return sum;  
} 
int main(){
	int n,m,cost,i,fu,fv,f,k,ans,ans1;   
	while (cin>>n>>m) {   
		for (i=0;i<m;i++)cin>>edge[i].u>>edge[i].v>>edge[i].w; 
		k=m; 
		for (i=1;i<=n;i++) { 
			cin>>cost; 
			if (cost!=-1) { 
				edge[k].u=0; 
				edge[k].v=i; 
				edge[k++].w=cost; 
			}
		}
		for (int i=0;i<=n;i++)fa[i]=i; 
		for (i=0;i<m;i++) {   
			fu=find(edge[i].u);  
			fv=find(edge[i].v);  
			if (fu!=fv)fa[fu]=fv;  
		}
		f=find(1); 
		for (i=2;i<=n;i++)
			if (f!=find(i)) break; 
		if (i==n+1){ 
			ans=route(n,m); 
			ans1=route(n,k);  
			if (ans>ans1)cout<<ans1<<endl; 
			else cout<<ans; 
			continue; 
		} 
		cout<<route(n,k)<<endl;   
	}
	return 0;  
}
