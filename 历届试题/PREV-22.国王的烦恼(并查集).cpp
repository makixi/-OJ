#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 10000 + 10;
struct node {
	int from, to, w;
	node(int ff,int tt,int ww):from(ff),to(tt),w(ww){}
	bool operator < (const node &a)const {
		return w > a.w;
	}
};
int fa[maxn];
int find(int x) {
	int a = x;
	while (x != fa[x])x = fa[x];
	while (a != fa[a]) {
		int tmp = a;
		a = fa[a];
		fa[tmp] = x;
	}
	return x;
}
int main() {
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<node>e;
	for (int i = 1; i <= n; ++i)fa[i] = i;
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		e.push_back(node(a, b, c));
	}
	sort(e.begin(), e.end());
	int pre = -1, res = 0;
	for (int i = 0; i < m; ++i) {
		int u = e[i].from, v = e[i].to, d = e[i].w;
		u = find(u), v = find(v);
		if (u == v)continue;
		fa[u] = v;
		if (d != pre) {
			pre = d;
			++res;
			n--;
			if (n==1)break;
		}
	}
	cout << res << "\n";
	return 0;
}
