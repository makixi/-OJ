#include<iostream>
#include<map>
using namespace std;
const int maxn=101;
int maze[maxn][maxn];
int m,n,t,x,y;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int main(){ 
	ios::sync_with_stdio(false);
	map<char,int> mm;
	mm['U']=0;
	mm['R']=1;
	mm['D']=2;
	mm['L']=3;
	cin>>m>>n;
	for(int i=0;i<m;++i)
		for(int j=0;j<n;++j)
			cin>>maze[i][j];
	char cs;
	cin>>x>>y>>cs>>t;
	int st=mm[cs];
	while(t--){
		if(maze[x][y]){
			st=(st+1)%4;
			maze[x][y]=0;
			x+=dx[st];y+=dy[st];
		}else{
			st=(st-1+4)%4;
			maze[x][y]=1;
			x+=dx[st];y+=dy[st];
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
