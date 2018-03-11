#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn=30;
int n;
int dis[maxn][maxn];
struct node{
	int id;
	int pri;
	node(){}
	node(int ii,int pp):id(ii),pri(pp){}
};
bool cmp(node a,node b){
	if(a.id!=b.id)return a.pri<b.pri;
	return a.id<b.id;
}
struct edge{
	int v;
	int w;
	edge(int vv,int ww):v(vv),w(ww){}
};
void init(){
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j){
			dis[i][j]=1;
			dis[i][j]=abs(i-j)+1;
		}
}
int main()  {  
	ios::sync_with_stdio(false);
    while(cin>>n&&n){
    	init();
    	vector<node> v;
    	vector<edge> e[maxn];
    	for(int i=0;i<n;++i){
    		int st,k;
    		cin>>st>>k;
    		while(k--){
    			int des,tmp;
				cin>>des>>tmp;
    			e[st].push_back(edge(des,tmp));
			}
		}
		int id;
		while(cin>>id&&id){
			int res=0;
			vector<int> ar(maxn),depart(maxn);
			for(int i=0;i<n;++i){
				int tmp;
				cin>>tmp;
				ar[tmp]=i;//记录位置 
			}
			for(int i=0;i<n;++i){
				int tmp;
				cin>>tmp;
				depart[tmp]=i;//记录位置 
			}
			for(int i=1;i<=n;++i)
				for(int j=0;j<e[i].size();++j){
					int v=e[i][j].v;
					res+=dis[ar[i]][depart[v]]*e[i][j].w;
				}
			v.push_back(node(id,res));
		}
		sort(v.begin(),v.end(),cmp);
		cout<<"Configuration Load\n";
		for(int i=0;i<v.size();++i)
			cout<<"    "<<v[i].id<<"         "<<v[i].pri<<endl;
	}
    return 0;  
}  
