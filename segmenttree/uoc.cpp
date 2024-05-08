#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=2e5+7;

int st[4*maxn];
int n, q, a[maxn], p[maxn];

void build(int id, int l, int r)
{
	if (l==r)
	{
		st[id]=a[l];
		int tmp=l;
		while (tmp%2==0) tmp/=2;
		st[id]+=a[tmp];
		return;
	}
	int mid=(l+r)/2;
	build(2*id, l, mid);
	build(2*id+1, mid+1, r);
	st[id]=st[2*id]+st[2*id+1];
}

void go(int id, int l, int r, int pos, int val)
{
	if (pos<l||pos>r) return;
	if (l==r)
	{
		st[id]=a[l];
		st[id]+=val;
		return;
	}
	int mid=(l+r)/2;
	go(2*id, l, mid, pos, val);
	go(2*id+1, mid+1, r, pos, val);
	st[id]=st[2*id]+st[2*id+1];
}

void update(int id, int l, int r, int pos, int val)
{
	if (pos<l||pos>r) return;
	if (l==r)
	{
		st[id]=val;
		a[l]=val;
		int tmp=l;
		while (tmp%2==0) tmp/=2;
		st[id]+=a[tmp];
		if (l&1)
		{
			for (int i=1; p[i]<=n; i++)
			{
				go(1, 1, n, p[i]*pos, val);
			}
		}
		return;
	}
	int mid=(l+r)/2;
	update(2*id, l, mid, pos, val);
	update(2*id+1, mid+1, r, pos, val);
	st[id]=st[2*id]+st[2*id+1];
}

int get(int id, int l, int r, int u, int v)
{
	if (v<l||r<u) return 0;
	if (u<=l&&r<=v)
	{
		return st[id];
	}
	int mid=(l+r)/2;
	return get(2*id, l, mid, u, v)+get(2*id+1, mid+1, r, u, v);
}

signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> q;
	for (int i=1; i<=n; i++) cin >> a[i];
	p[0]=1;
	for (int i=1; i<20; i++) p[i]=2*p[i-1];	
	build(1, 1, n);
	while (q--)
	{
		int t, l, r; cin >> t >> l >> r;
		if (t==1)
		{
			update(1, 1, n, l, r);
		}
		else cout<<get(1, 1, n, l, r)<<endl;
	}
}

