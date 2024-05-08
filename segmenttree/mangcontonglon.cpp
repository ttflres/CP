#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=2e5+7;

int n, q, a[maxn];

struct node
{
    int g, l, r, s;
    node() {}
	node(int val) {
		s = g = l = r = val;
	}
} segtree[4*maxn];

node merge(node a, node b)
{
    node ret;
    ret.s=a.s+b.s;
    ret.l=max(a.l, a.s+b.l);
    ret.r=max(b.r, b.s+a.r);
    ret.g=max(a.g, max(b.g, a.r+b.l));
    return ret;
}

void build(int id, int l, int r)
{
    if (l==r)
    {
        segtree[id] = node(a[l]);
        return;
    }
    int mid=(l+r)/2;
    build(2*id, l, mid);
    build(2*id+1, mid+1, r);
    segtree[id]=merge(segtree[2*id],segtree[2*id+1]);
}

node get(int id, int l, int r, int u, int v)
{
    if (v<l||r<u) return node(-1000000000);
    if (u<=l&&r<=v) return segtree[id];
    int mid=(l+r)/2;
    return merge(get(2*id, l, mid, u, v),get(2*id+1, mid+1, r, u, v));
}


signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);
   cin >> n;
   for (int i=1; i<=n; i++) cin >> a[i];
   build(1, 1, n);
   cin >> q;
   while (q--)
   {
       int x, y; cin >> x >> y;
       cout<<get(1, 1, n, x, y).g<<endl;
   }
}
