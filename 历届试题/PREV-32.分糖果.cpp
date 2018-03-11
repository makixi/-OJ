#include<iostream>
using namespace std;
int n,candy[110],tmp[110];
bool same(){
	for(int i=2;i<=n;++i)
		if(candy[i]!=candy[1])return false;
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	int res=0;
	cin>>n;
	for(int i=1;i<=n;++i)cin>>candy[i];
	while(true){
		if(same()){
			cout<<res;
			break;
		}
		for(int i=1;i<=n;++i)
			tmp[i]=candy[i]/2,candy[i]/=2;
		tmp[0]=tmp[n];
		for(int i=1;i<=n;++i){
			candy[i]+=tmp[i-1];
			if(candy[i]&1){
				candy[i]++;
				res++;
			}
		}
		
	}
	return 0;
} 
