#include<bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 69;
const int logN = 20;

int n, m;
vector<int> adj[maxN];
int depth[maxN];
int up[logN][maxN];
int a[maxN];

void dfs(int u, int p) {
    up[0][u] = p;
    for (int i = 1; i < logN; i++)
        up[i][u] = up[i - 1][up[i - 1][u]];
    for (int& v: adj[u])
    if (v != p) {
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
}

int lca(int u, int v) {
    if (depth[u]!=depth[v])
    {
        if (depth[u]<depth[v]) swap(u, v);
        int k=depth[u]-depth[v];
        for (int j=0; (1<<j)<=k; j++)
        {
            if (k>>j&1) u=up[j][u];
        }
    }
    if (u==v) return u;
    int k=__lg(depth[u]);
    for (int j=k; j>=0; j--)
    {
        if (up[j][u]!=up[j][v]) u=up[j][u], v=up[j][v];
    }
    return up[0][u];
}

signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i=1; i<=n; i++) cin >> a[i];
	for (int i=1; i<n; i++)
	{
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, 0);
	
}
