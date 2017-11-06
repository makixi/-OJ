#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int pre[10010],s[10010];
typedef struct IN{
    int a,b;
    int c;
}IN;
IN mp[100010];
int N,P;
int cmp(const void *a,const void *b){
    return (*(IN *)a).c - (*(IN *)b).c;
}
int find(int x){
    int t,r=x;
    while(r!=pre[r])r=pre[r];
    while(x!=r){
        t=pre[x];
        pre[x]=r;
        x=t;
    }
    return r;
}
int krcuskal(){
    int pa,pb,sum=0,count=0;
    memset(pre,0,sizeof(pre));
    for(int i=1;i<=N;i++)pre[i]=i;
    for(int i=0;i<P;i++){
        pa=find(mp[i].a);
        pb=find(mp[i].b);
        if(pa!=pb){
            pre[pa]=pb;
            sum+=mp[i].c;
            count++;
        }
    }
    return sum;
}
int main(){
    int a,b,c,min=2001;
    scanf("%d %d",&N,&P);
    for(int i=1;i<=N;i++){
        scanf("%d",&s[i]);
        if(s[i]<min)min=s[i];
    }
    for(int i=0;i<P;i++){
        scanf("%d %d %d",&mp[i].a,&mp[i].b,&c);
        mp[i].c=2*c+s[mp[i].a]+s[mp[i].b];
    }
    qsort(mp,P,sizeof(mp[0]),cmp);
    printf("%d\n",krcuskal()+min);
    return 0;
}
