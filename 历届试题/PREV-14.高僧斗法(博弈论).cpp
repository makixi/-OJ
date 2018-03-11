#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=110;
int a[maxn],b[maxn]; 
int main(){
	int n=0,sum=0;
	while(~scanf("%d",&a[n]))++n;
	for(int i=1;i<n;++i)b[i-1]=a[i]-a[i-1]-1;
	for(int i=0;i<n-1;i+=2)sum^=b[i];
	if(sum==0){
		cout<<-1<<endl;
		return 0;
	}
	for(int i=0;i<n-1;++i)
		for(int j=1;a[i]+j<a[i+1];++j){//ÒÆ¶¯j²½ 
			b[i]-=j;
			if(i)b[i-1]+=j;
			sum=0;
			for(int k=0;k<n-1;k+=2)sum^=b[k];
			if(!sum){
				cout<<a[i]<<" "<<a[i]+j<<"\n";
				break;
			}
			b[i]+=j;
			if(i)b[i-1]-=j;
		}
	return 0;
}
