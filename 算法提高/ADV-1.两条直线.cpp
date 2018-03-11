#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
const int N = 100000;
struct P { 
	int x, y; 
}d[N + 5];
bool cmp(P a, P b) {return a.x == b.x?a.y<b.y:a.x<b.x;}
struct F {
	double maxn, minn;
}fl[N + 5], fr[N + 5];
bool check(double m, int n) {
	m *= 2;
	int i, j = 0;
	for (i = 0; i<n; i++) {
		while (j<n&&d[j].x - d[i].x <= m)j++;
		double MAX = -1e10;
		double MIN = 1e10;
		if (j != n) {
			MAX = max(MAX, fr[j].maxn);
			MIN = min(MIN, fr[j].minn);
		}
		if (i - 1 >= 0) {
			MAX = max(MAX, fl[i - 1].maxn);
			MIN = min(MIN, fl[i - 1].minn);
		}
		if (MAX - MIN <= m)return true;
	}
	return false;
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i<n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		d[i].x = x + y;
		d[i].y = x - y;
	}
	sort(d, d + n, cmp);
	fl[0].minn = fl[0].maxn = d[0].y;
	for (int i = 1; i<n; i++) {
		fl[i].maxn = max(fl[i - 1].maxn, d[i].y*1.0);
		fl[i].minn = min(fl[i - 1].minn, d[i].y*1.0);
	}
	fr[n - 1].minn = fr[n - 1].maxn = d[n - 1].y;
	for (int i = n - 2; i >= 0; i--) {
		fr[i].maxn = max(fr[i + 1].maxn, d[i].y*1.0);
		fr[i].minn = min(fr[i + 1].minn, d[i].y*1.0);
	}
	double l = 0.0;
	double r = 1000000000;
	while (r - l >= 0.01) {
		double m = (l + r) / 2;
		if (check(m, n))r = m;
		else l = m;
	}
	printf("%.1f\n", r);
	return 0;
}
