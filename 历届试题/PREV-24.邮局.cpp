#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
struct node {
	double x, y;
}hourse[55], mail[30];
const int inf = 0x3f3f3f3f;
double d[55][30];//i户人家到j邮筒距离
double dis(node a, node b) {
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}
int count1(ll n) {
	int ans = 0;
	while (n)++ans, n &= (n - 1);
	return ans;
}
void getState(vector<int> &res, ll n) {
	int pos = 1;
	while (n) {
		if (n & 1)res.push_back(pos);
		++pos;
		n >>= 1;
	}
}
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i<n; ++i)cin >> hourse[i].x >> hourse[i].y;
	for (int i = 0; i<m; ++i)cin >> mail[i].x >> mail[i].y;
	for (int i = 0; i<n; ++i)
		for (int j = 0; j<m; ++j) 
			d[i][j] = dis(hourse[i], mail[j]);
	vector<int> res;
	double resdis = (double)inf;
	for (ll st = 1; st<(1 << m); ++st) {
		if (count1(st) != k)continue;
		double sum = 0.0;
		for (int i = 0; i<n; ++i) {
			double minn = (double)inf;
			for (int j = 0; j<m; ++j)
				if ((st >> j) & 1) 
					minn = min(minn, d[i][j]);//家最近的邮局
			sum += minn;
		}
		if (sum<resdis) {
			resdis = sum;
			res.clear();
			getState(res, st);
		}
	}
	for (int i = 0; i<res.size(); ++i) {
		if (i)cout << " ";
		cout << res[i];
	}
	return 0;
}
