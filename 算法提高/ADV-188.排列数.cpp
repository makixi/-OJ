#include<iostream>
#include<algorithm>
using namespace std;
int a[10]={0,1,2,3,4,5,6,7,8,9};
int main(){
	int cnt=1;
	int n;
	cin>>n;
	while(cnt<n){
		++cnt;
		next_permutation(a,a+10);
	}
	for(int i=0;i<10;++i)cout<<a[i];
	return 0;
}
