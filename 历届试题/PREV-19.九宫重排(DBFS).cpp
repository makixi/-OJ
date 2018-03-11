#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;
string s,t;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
map<string,int> vis1;
map<string,int> vis2;
struct node{
	string state;
	int step;
	node(string ss,int tt):state(ss),step(tt){}
};
bool judge(int x,int y){
	if(x<0||y<0||x>=3||y>=3)return false;
	return true;
}
int bfs(){
	queue<node> q1,q2;
	q1.push(node(s,0));vis1[s]=1;
	q2.push(node(t,0));vis2[t]=1;
	while(!q1.empty()||!q2.empty()){
		int step;
		string str;
		int flag=0;
		if(q1.size()<=q2.size()){
			node nd=q1.front();q1.pop();
			str=nd.state;
			flag=1;
			step=nd.step;
			if(vis2[str]) return nd.step+vis2[str];
		}else{
			node nd=q2.front();q2.pop();
			str=nd.state;
			flag=2;
			step=nd.step;
			if(vis1[str]) return nd.step+vis1[str];
		}
		int pos;
		for(int i=0;i<9;++i)
			if(str[i]=='.'){
				pos=i;
				break;
			}
		int row=pos/3,col=pos%3;
		for(int i=0;i<4;++i){
			int nx=row+dx[i];
			int ny=col+dy[i];
			if(judge(nx,ny)){
				int npos=nx*3+ny;
				string ss=str;
				swap(ss[pos],ss[npos]);
				if(flag==1&&!vis1[ss]){
					vis1[ss]=step+1;
					q1.push(node(ss,step+1));
				}else if(flag==2&&!vis2[ss]){
					vis2[ss]=step+1;
					q2.push(node(ss,step+1));
				}
			}
		}
	}
	return -1;
}
int main(){
	ios::sync_with_stdio(false); 
	cin>>s>>t;
	cout<<bfs()<<endl;
	return 0;
}
