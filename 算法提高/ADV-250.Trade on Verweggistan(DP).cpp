#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
set<int> res;
int dp[51][22];
int v[51][22];
int main(){
	ios::sync_with_stdio(false); 
	int w,cas=1;
	while(cin>>w&&w){
		res.clear();
		memset(dp,0,sizeof(dp));
		memset(v,0,sizeof(v));
		for(int i=1;i<=w;++i){
			cin>>v[i][0];
			for(int j=1;j<=v[i][0];++j)cin>>v[i][j];
		}
		int resnum=0;
		for(int i=1;i<=w;++i){
			int maxn=0;
			vector<int> tmp;
			set<int> ss=res;
			res.clear();
			for(int j=1;j<=v[i][0];++j){
				dp[i][j]=dp[i][j-1]+10-v[i][j];
				maxn=max(maxn,dp[i][j]);
			}
			resnum+=maxn;
			if(maxn==0)tmp.push_back(0);
			for(int j=1;j<=v[i][0];++j)
				if(dp[i][j]==maxn)
					tmp.push_back(j);
			if(ss.size())
				for(set<int>::iterator it=ss.begin();it!=ss.end();++it)
					for(int j=0;j<tmp.size();++j)
						res.insert(*it+tmp[j]);
			else
				for(int j=0;j<tmp.size();++j)
					res.insert(tmp[j]);
		}
		printf("Workyards %d\n",cas++);
		printf("Maximum profit is %d.\n",resnum);
		printf("Number of pruls to buy:");
		int cnt=1;
		for(set<int>::iterator it=res.begin();it!=res.end()&&cnt<=10;++it,++cnt)
			cout<<" "<<*it;
		cout<<"\n";
	}
	return 0;
}
