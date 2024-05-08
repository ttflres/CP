#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+7;

int n, k, m, t;
vector<pair<int, pair<int, int>>> g;
int par[maxn];

int find(int u)
{
	if (par[u]<0) return u;
	return par[u]=find(par[u]);
}

bool unite(int u, int v)
{
	if ((u=find(u))==(v=find(v))) return false;
	if (par[u]>par[v]) swap(u,v);
	par[u]+=par[v];
	par[v]=u;
	return true;
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> k >> m >> t;
	for (int i=1; i<=n; i++)
	{
		int a; cin >> a;
		par[i]=-1;
	}
	for (int i=1; i<=m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		g.push_back({w, {u, v}});
	}
	sort(g.begin(), g.end());
	int ans=0;
	for (auto z:g)
	{
		if (unite(z.second.first, z.second.second)) ans+=z.first;
	}
	cout<<ans;
}
