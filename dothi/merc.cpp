#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e5+7;

int n, m, k;
vector<int> g[maxn];
int low[maxn], num[maxn], timeDFS=0;
vector<pair<int, int>> liu[maxn];
int d[maxn], up[20][maxn], height[maxn];

void dfs(int u, int p)
{
	low[u]=num[u]=++timeDFS;
	for (auto v:g[u])
	{
		if (v==p) continue;
		if (!num[v])
		{
			dfs(v, u);
			low[u]=min(low[u], low[v]);
			if (low[v]==num[v])
			{
				liu[u].push_back({v, 1});
				liu[v].push_back({u, 1});
			}
			else
			{
				liu[u].push_back({v, 0});
				liu[v].push_back({u, 0});
			}
		}
		else 
		{
			low[u]=min(low[u], num[v]);	
		}
	}
}

void bfs(int u)
{
	for (auto v:liu[u])
    if (v.first != up[0][u]) {
    	up[0][v.first]=u;
    	for (int i=1; i<20; i++)
		{
			up[i][v.first]=up[i-1][up[i-1][v.first]];
		}
    	height[v.first]=height[u]+v.second;
        d[v.first] = d[u] + 1;
        bfs(v.first);
    }
}

int lca(int u, int v)
{
	if (d[u]!=d[v])
	{
		if (d[u]<d[v]) swap(u,v);
		int k=d[u]-d[v];
		for (int i=1; (1<<i)<=k; i++)
		{
			if (k>>i&1) u=up[i][u];
		}
	}
	if (u==v) return u;
    int k=__lg(d[u]);
    for (int j=k; j>=0; j--)
    {
        if (up[j][u]!=up[j][v]) u=up[j][u], v=up[j][v];
    }
    return up[0][u];
}

int dist(int u, int v)
{
	int c=lca(u, v);
	return height[u]+height[v]-2*height[c];
}

signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("MERC.INP", "r", stdin);
	freopen("MERC.OUT", "w", stdout);
	cin >> n >> m;
	for (int i=1; i<=m; i++)
	{
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 1);
	bfs(1);
	cin >> k;
	while (k--)
	{
		int a, b; cin >> a >> b;
		cout<<dist(a, b)<<endl;
	}
}

/*7 8
1 2
2 3
3 4
4 5
5 6
5 7
3 5
4 7*/

