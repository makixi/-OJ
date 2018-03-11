#include <iostream>
#include <cstdio>
#include <vector> 
#include <cstring>
using namespace std;
const int maxn=14;
int like[maxn][maxn];
int dp[2][1<<maxn];
int N;
vector<int> v[maxn];
int CountOfOne( int n ){
	int cnt = 0;
	do{cnt += (n&1);}while(n>>=1);
	return cnt;
}
inline int lowBit( int n ){ return n&(-n); }
int lowBitPos( int n ){
	int cnt = 0;
	while( n & 1 ){
		++cnt;
		n >>= 1;
	}
	return cnt;
}
int main() {
	scanf("%d",&N);
	for( int i = 0, End=(1<<N); i < End; ++i)
		v[ CountOfOne(i) ].push_back( i );
	for( int i=0,j; i < N; ++i)
		for( j=0; j < N; ++j )scanf("%d",&like[i][j]);			
	int E=0;
	for( int i = 1; i <= N; ++i ){
		E = 1-E;
		for( vector<int>::iterator it=v[i].begin(), End=v[i].end(); it != End; ++it )
			for(int status = *it, temp=*it, times=0, lb; times < i; ++times){
				lb = ~lowBit(temp);
				dp[E][status] = max(dp[E][status], dp[1-E][status&lb]+like[i-1][lowBitPos(lb)]);
				temp &= lb;
			}
	}
	printf("%d",dp[E][(1<<N)-1]);
	return 0;
} 
