#include<cstdio>  
#include<algorithm>  
#include<cstring>  
using namespace std;  
int n, m;   
int a[11][11], all = 0, ans = 11*11;  
int dir[4][2] = {0,1, 0,-1, -1,0, 1,0};  
int vis[11][11];    
void dfs(int x, int y, int sum, int cnt)  {  
    if(sum > all/2) return;  
    if(sum == all/2)ans = min(ans,cnt);   
    for(int i = 0; i < 4; i++){  
        int xx = x + dir[i][0];  
        int yy = y + dir[i][1];  
        if(xx >= 0 && xx < m && yy >= 0 && yy < n && !vis[xx][yy]){  
            vis[xx][yy] = 1;  
            dfs(xx,yy, sum+a[xx][yy], cnt+1);  
            vis[xx][yy] = 0;  
        }  
    }  
}  
int main()  {  
    scanf("%d%d", &n, &m);  
    for(int i = 0; i < m; i++)  
    	for(int j = 0; j < n; j++){  
        	scanf("%d",&a[i][j]);  
        	all += a[i][j]; 
    	}    
    memset(vis,0,sizeof(vis));  
    vis[0][0] = 1;  
    dfs(0,0,a[0][0],1);      
    if(ans == 11*11)printf("-1");  
    else printf("%d\n",ans);   
    return 0;
}  
