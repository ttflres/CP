#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=2222;

struct edge
{
	int u, v, w;
	bool operator < (const edge &o) const\
	{
		return w<o.w;
	}
};

int n;
vector<edge> v;
vector<pair<int, int>> g[maxn];
int ans=1, res=0;
int p[maxn], sz[maxn], d[maxn][maxn];

void init()
{
	for (int i=1; i<=n; i++)
	{
		sz[i]=1;
		p[i]=i;
	}
}

int findset(int u)
{
	return (u==p[u])?u:p[u]=findset(p[u]);
}

bool un(int u, int v)
{
	u=findset(u), v=findset(v);
	if (u==v) return false;
	else
	{
		if (sz[u]<sz[v]) swap(u, v);
		sz[u]+=sz[v];
		p[v]=u;
		return true;
	}
}

bool dfs(int u, int p, int sc, int dis)
{
	if (d[sc][u]!=dis||(u!=sc&&d[sc][u]==0)) return false;
	int ok=1;
	for (auto x:g[u])
	{
		if (x.first!=p)
		{
			ok&=dfs(x.first, u, sc, dis+x.second);
		}
	}
	return ok;
}


signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	init();
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
		{
			cin >> d[i][j];
			if (i==j&&d[i][j]!=0) ans=0;
			else
			{
				if (j<i&&d[i][j]!=d[j][i]) ans=0;
				else if (i<j) v.push_back({i, j, d[i][j]});
			}
		}
	}
	sort(v.begin(), v.end());
	int t=0;
	for (auto x:v)
	{
		if (t==n) break;
		if (un(x.u, x.v))
		{
			t=max(t, sz[findset(x.u)]);
			g[x.u].push_back({x.v, x.w});
			g[x.v].push_back({x.u, x.w});	
		}
	}
	for (int i=1; i<=n; i++) ans&=dfs(i, 0, i, 0);
	if (ans) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}

