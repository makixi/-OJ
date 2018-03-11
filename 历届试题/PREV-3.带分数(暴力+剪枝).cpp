#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int res,n;
int a[10]={0,1,2,3,4,5,6,7,8,9};
int sum(int st,int de){
	int ans=0;
	for(int i=st;i<=de;++i)ans=ans*10+a[i];
	return ans;
}
void solve(){
	int num1,num2,num3;//n=num1+num2/num3
	for(int i=1;i<=8;++i){
		num1=sum(1,i);
		if(num1>=n)return;
		for(int j=i+(9-i)/2;j<9;++j){
			num2=sum(i+1,j);
			num3=sum(j+1,9);
			if(num2>num3&&num2%num3==0&&n==num1+num2/num3)++res;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	do{solve();}while(next_permutation(a+1,a+10));
	cout<<res;
	return 0;
}
