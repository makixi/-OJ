#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int  N = 100001;
struct edge{
	int to;
	int weight;
	int nex;
}edges[2 * N];
int tree[N];
int d[N][12];
int K;
int tot = 0;
void add_edge(int x, int y, int w){
	edges[tot].to = y;
	edges[tot].weight = w;
	edges[tot].nex = tree[x];
	tree[x] = tot++;
}
void dfs(int r, int p){
	for (int cur = tree[r]; cur != -1; cur = edges[cur].nex){
		int child = edges[cur].to;
		if (child == p)continue;
		dfs(child, r);
		for (int i = K; i >= 0; i--){
			d[r][i] += d[child][0] + edges[cur].weight * 2;//Ҫ�߱�����ÿһ�����
			for (int j = 1; j <= i; j++)d[r][i] = min(d[child][j] + d[r][i - j] + j * edges[cur].weight, d[r][i]);
			//��r����i��������=min(��child����j��������+��r����i-j��������+j*����֮����룬ԭֵ)
		}
	}
}
int main(){
	memset(tree, -1, sizeof(tree));
	int n, S;
	cin >> n >> S >> K;
	for (int i = 0; i < n - 1; i++){
		int a, b, c;
		cin >> a >> b >> c;
		add_edge(a, b, c);
		add_edge(b, a, c);
	}
	dfs(S, -1);
	cout << d[S][K] << endl;
	return 0;
}

