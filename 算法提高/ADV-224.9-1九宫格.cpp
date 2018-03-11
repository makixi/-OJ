#include<iostream>
#include<stack>
#include<vector>
#include<set>
#include<cstring>
#include<string>
using namespace std;
typedef long long ll;
int a[3][3];
int main() {
	ios::sync_with_stdio(false);
	for(int i=0;i<3;++i)
		for(int j=0;j<3;++j)cin>>a[i][j];
	int col[3],row[3],line1=0,line2=0;
	memset(col,0,sizeof(col));
	memset(row,0,sizeof(row));
	for(int i=0;i<3;++i)
		for(int j=0;j<3;++j){
			col[j]+=a[i][j];
			row[i]+=a[i][j];
			if(i==j)line1+=a[i][j];
			if(i+j==2)line2+=a[i][j];
		}
	set<int> s;
	s.insert(line1);s.insert(line2);
	for(int i=0;i<3;++i){
		s.insert(col[i]);
		s.insert(row[i]);
	}
	if(s.size()>1)cout<<0;
	else cout<<1;
	return 0;
}
