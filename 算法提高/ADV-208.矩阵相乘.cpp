#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	long long int a,b,c,d,i,j,k;
	long long int arr1[1000][1000],arr2[1000][1000],s[1000][1000]={0};
	scanf("%lld%lld",&a,&b);
	for(i=0;i<a;i++)
		for(j=0;j<b;j++)scanf("%lld",&arr1[i][j]);
	scanf("%lld%lld",&c,&d);
	for(i=0;i<c;i++)
		for(j=0;j<d;j++)scanf("%lld",&arr2[i][j]);
	for(i=0;i<a;i++)
		for(j=0;j<b;j++)
			for(k=0;k<d;k++)
				s[i][k]+=arr1[i][j]*arr2[j][k];
	for(i=0;i<a;i++){
		for(j=0;j<d;j++)printf("%lld ",s[i][j]);
		printf("\n");
	}
	return 0;
}
