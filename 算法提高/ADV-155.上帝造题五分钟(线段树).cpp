#include <iostream>
using namespace std;
const int maxn=2000;
const int inf=0x3f3f3f3f;
int n;
struct Tree{
	int l,r,val;
	int minn;
}tree[maxn<<2];
void build(int st, int l, int r) {
	tree[st].l = l; tree[st].r = r;
	if (l == r) return;
	int mid = (l + r) >> 1;
	build(st << 1, l, mid);
	build(st << 1 | 1, mid + 1, r);
}
void insert(int st, int j, int value) {
    if(tree[st].l == tree[st].r) {
        tree[st].minn = value;
        tree[st].val = value;
        return ;
    }
    int mid = (tree[st].l + tree[st].r) / 2;
    if(j <= mid)insert(st<<1, j, value);
    else insert(st<<1|1, j, value);
    tree[st].minn = min(tree[st<<1].minn, tree[st<<1|1].minn);
}
int query(int st,int l,int r){
	if(tree[st].l==l&&tree[st].r==r)return tree[st].minn;
	int mid = (tree[st].l + tree[st].r) / 2;
    if(r <= mid)return query(st<<1, l, r);
    else if(l > mid)return query(st<<1|1, l, r);
    else return min(query(st<<1, l, mid), query(st<<1|1, mid+1, r));
}
int main() {
	int q;
	scanf("%d%d",&n,&q);
	build(1,0,n-1);
	for(int j = 0; j < n; j++) {
		int value;
        scanf("%d",&value);
        insert(1, j, value);
    }
	while(q--){
		int l,r;
		scanf("%d%d",&l,&r);
		cout<<query(1,l,r)<<"\n";
	}
    return 0;
}
