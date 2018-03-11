#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
const int t = 100000;
int a[105], b[105], dp[105][200005], n, p, q;
int solve(int n){
    for (int i = 0; i < n; i++)
        for (int j = -t; j <= t; j++)dp[i][j + t] = -INF;
    for (int i = 0; i < n; i++)dp[i][a[i] + t] = b[i];
    for (int i = 1; i < n; i++)
        for (int j = -t; j <= t; j++){
            dp[i][j + t] = max(dp[i - 1][j + t], dp[i][j + t]);
            if (j + t - a[i] < 0 || j + t - a[i] > 200000)continue;
            dp[i][j + t] = max(dp[i][j + t], dp[i - 1][j + t - a[i]] + b[i]);
        }
    int ans = -INF;
    for (int j = 0; j <= t; j++)
        ans = max(ans, dp[n - 1][j + t] >= 0 ? j + dp[n - 1][j + t] : -INF);
    return ans;
}
int main(){
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; i++){
        cin >> p >> q;
        if (p < 0 && q < 0)continue;
        a[cnt] = p;
        b[cnt++] = q;
    }
    int ans = solve(cnt);
    if (ans <= -INF)cout << "0" << endl;
    else cout << ans << endl;
    return 0;
}
