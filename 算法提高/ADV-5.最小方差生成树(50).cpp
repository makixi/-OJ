#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int inf = 0x3f3f3f3f;
int fa[55], tmp[1010];
int n, m;
double ans;
struct edge {
	int u, v;
	double w, val;
}e[1010];
bool cmp(edge a, edge b) { return a.w < b.w; }
int Find(int x) { return x == fa[x] ? x : fa[x] = Find(fa[x]); }
void Union(int a, int b) {
	int r1 = Find(a), r2 = Find(b);
	if (r1 != r2)fa[r2] = r1;
}
void Kruskal(int sum) {
	for (int i = 1; i <= n; i++)fa[i] = i;
	int cnt = 0;
	double f_all = 0,all = 0,ave = sum * 1.0 / (n - 1);
	for (int i = 0; i < m; i++)e[i].w = (e[i].val - ave) * (e[i].val - ave);
	sort(e, e + m, cmp);//最小方差
	for (int i = 0; i < m; i++) {
		int u = e[i].u;
		int v = e[i].v;
		if (Find(u) != Find(v)) {
			Union(u, v);
			f_all += e[i].w;
			all += e[i].val;
			cnt++;
		}
		if (cnt == n - 1)break;
	}
	if ((int)all == sum)ans = min(ans, f_all);
}
int main() {
	int ca = 1;
	while (scanf("%d %d", &n, &m) != EOF && (m + n)) {
		int minv = 0;
		int maxv = 0;
		ans = inf;
		for (int i = 0; i < m; i++) {
			scanf("%d %d %lf", &e[i].u, &e[i].v, &e[i].val);
			tmp[i] = e[i].val;
		}
		sort(tmp, tmp + m);
		for (int i = 0; i < n - 1; i++)minv += tmp[i];//最小值的最小生成树 
		for (int i = m - 1; i > m - n; i--)maxv += tmp[i];//最大值的最小生成树 
		for (int i = minv; i <= maxv; i++)Kruskal(i);
		ans /= (n - 1);
		printf("Case %d: %.2f\n", ca++, ans);
	}
	return 0;
}
