#include<iostream>
#include<cstring>
#define MAX 1000010
#define N 100010
using namespace std;
int C[MAX],b[MAX];
int num[N];
long long total[N],ans;
int lowbit(int x){return x&(-x);}
void add(int pos,int num){
	while(pos<=MAX){
		C[pos]+=num;
		pos+=lowbit(pos);
	}
}
int Sum(int pos){
	int sum=0;
	while(pos>0){
		sum+=C[pos];
		pos-=lowbit(pos);
	}
	return sum;
}
int main(){
	int i;
	total[0]=0;
	for(int i=1;i<=N;i++)
		total[i]=total[i-1]+i;//不高兴程度 
	int n;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>num[i];
		add(num[i]+1,1);		
		b[i]=i+1-Sum(num[i]+1);//左边多少比我大的 
	}
	memset(C,0,sizeof(C)); 
	for(i=n-1;i>=0;i--){
		add(num[i]+1,1);
		b[i]=b[i]+Sum(num[i]);//右边多少比我小的	
	}
	ans=0;
	for(i=0;i<n;i++)ans+=total[b[i]];//求和 
	cout<<ans<<endl;	
	return 0;
 } 
