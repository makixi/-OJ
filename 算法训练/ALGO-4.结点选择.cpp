#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 100000 + 1;
int  m;
int head[maxn];
int dp[maxn][2];//dp[i][0]第i个结点不选择时的最大w，dp[i][1]第i个结点选择时的最大w
struct node {
	int to;
	int nextNode;
}v[maxn*2];
void add(int st, int des) {
	v[m].to = des;
	v[m].nextNode = head[st];
	head[st] = m++;
}
void dfs(int curr, int pre) {
	for (int i = head[curr]; i != -1; i = v[i].nextNode) {
		if (v[i].to == pre)continue;
		dfs(v[i].to, curr);
		dp[curr][0] += max(dp[v[i].to][0], dp[v[i].to][1]);
		dp[curr][1] += dp[v[i].to][0];
	}
}
int main() {
	int n;
	cin >> n;
	memset(head, -1, sizeof(head));
	for (int i = 1; i <= n; ++i)cin >> dp[i][1];
	for (int i = 0; i < n - 1; ++i) {
		int st, des; cin >> st >> des;
		add(st, des);
		add(des, st);
	}
	dfs(1, 0);
	cout << max(dp[1][0], dp[1][1]);
	return 0;
}
