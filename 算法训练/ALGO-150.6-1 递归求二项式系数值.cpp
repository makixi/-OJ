#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
typedef long long ll;
int c(int n,int k){
	if(k==0||k==n)return 1;
	return c(n-1,k)+c(n-1,k-1);
}
int main(){
    int n,k;
    cin>>k>>n;
    cout<<c(n,k);
	return 0;
}
