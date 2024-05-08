#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e5+7;

int n;
vector<int> g[maxn];
int st[4*maxn], d[maxn], res[maxn];

void update(int id, int l, int r, int u, int v, int val)
{
	if (v<l||r<u) return;
	if (u<=l&&r<=v)
	{
		st[id]=val;
		return;
	}
	int mid=(l+r)/2;
	update(2*id, l, mid, u, v, val);
	update(2*id+1, mid+1, r, u, v, val);
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

void dfs(int u, int p)
{
	res[d[u]]=get(1, 1, n, 1, d[u]);
	update(1, 1, n, d[u], d[u], 1);
	for (auto x:g[u])
	{
		if (x!=p) dfs(x, u);
	}
	update(1, 1, n, d[u], d[u], 0);
}

signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i=1; i<n; i++)
	{
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i=1; i<=n; i++)
	{
		int x; cin >> x;
		d[x]=i;
	}
	dfs(1, 0);
	for (int i=1; i<=n; i++) cout<<res[i]<<endl;
}
