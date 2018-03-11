#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<string>
using namespace std;
const int inf=0x3f3f3f3f;
char a[512][512];
char op[4]={'D','L','R','U'};
int dx[4]={0,-1,1,0};
int dy[4]={1,0,0,-1};
int prex[512][512];
int prey[512][512];
int preop[512][512];
bool vis[512][512];
int n,m;
struct node{
	int x,y;
	int t;
	node(){}
	node(int xx,int yy,int tt):x(xx),y(yy),t(tt){}
};
bool judge(int x,int y){
	if(x<1||y<1||x>m||y>n)return false;
	if(vis[x][y]||a[x][y]=='1')return false;
	return true;
}
void printpre(int x,int y){
	if(x==1&&y==1)return;
	printpre(prex[x][y],prey[x][y]);
	cout<<op[preop[x][y]];
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)cin>>a[j][i];
	queue<node> q;
	q.push(node(1,1,0));
	vis[1][1]=true;
	while(!q.empty()){
		node nd=q.front();q.pop();
		if(nd.x==m&&nd.y==n){
			cout<<nd.t<<endl;
			printpre(nd.x,nd.y);
			break;
		}
		for(int i=0;i<4;++i){
			int nx=nd.x+dx[i];
			int ny=nd.y+dy[i];
			if(judge(nx,ny)){
				prex[nx][ny]=nd.x;
				prey[nx][ny]=nd.y;
				preop[nx][ny]=i;
				vis[nx][ny]=true;
				q.push(node(nx,ny,nd.t+1));
			}
		}
	}
    return 0;
}
