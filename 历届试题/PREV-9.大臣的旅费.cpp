#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
struct node{
    int to,cost;
};
vector<node>G[10010];
int vis[10010];
int a,b,c,n;
int temp;
long long ans=-99999;
void dfs(int s,int dist){
    if(ans<dist) ans=dist,temp=s;
    for(int i=0;i<G[s].size();i++){
        node p=G[s][i];
        if(!vis[p.to]&&p.cost){
            vis[p.to]=1;
            dist+=p.cost;
            dfs(p.to,dist);
            vis[p.to]=0;
            dist-=p.cost;
        }
    }
    return;
}
int main(){
    cin>>n;
    node p;
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++) G[i].clear();
    for(int i=0;i<n-1;i++){
        cin>>a>>b>>c;
        p.to=b;
        p.cost=c;
        G[a].push_back(p);
        p.to=a;
        G[b].push_back(p);
    }
    vis[1]=1;
    dfs(1,0);               //  �����·��ʼ�㣻
    memset(vis,0,sizeof(vis));
    vis[temp]=1;
    ans=-99999;
    dfs(temp,0);            //  ����ʼ������������·��
    cout<<((11+10+ans)*ans)/2<<endl;
    return 0;
}
