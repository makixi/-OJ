#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
int n;
int sum(int num){
	int res=0;
	while(num){
		res+=num%10;
		num/=10;
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false); 
	cin>>n;
	for(int i=10000;i<=999999;++i){
		if(sum(i)!=n)continue;
		string str=to_string(i);
		string tmp=str;
		reverse(tmp.begin(),tmp.end());
		if(tmp==str)cout<<i<<"\n";
	} 
	return 0;
}
