#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(false);
	vector<int> v;
	int n;
	while(cin>>n&&n)v.push_back(n);
	for(int i=v.size()-1;i>=0;--i){
		cout<<v[i];
		if(i)cout<<" ";
	}
	return 0;
}
