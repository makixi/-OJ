#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int a[12000],b[12000],vis[12000],n,m;
vector<int> g[12000];
bool dfs(int i){
	vis[i]=1;
	for(int j=g[i].size()-1;j>=0;j--)
		if(!vis[g[i][j]]&&dfs(g[i][j])){
			vis[i]=0;
			return false;
		}
	vis[i]=0;
	return true;
}
int main(){
	while(~scanf("%d",a+n)){
		for(int i=0;i<n;i++)
			if(a[i]%a[n]==0||a[n]%a[i]==0){
				g[i].push_back(n);
				g[n].push_back(i);
			}
		n++;
		if(getchar()=='\n')
		break;
	}
	while(~scanf("%d",b+m)){
		m++;
		if(getchar()=='\n')
		break;
	}
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			if(b[i]==a[j])
				if(dfs(j)){
					cout<<a[j]<<endl;
					return 0;
				}
	cout<<-1<<endl;
	return 0;
}
