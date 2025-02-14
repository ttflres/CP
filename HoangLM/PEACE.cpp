#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 69;
const int logN = 20;

int n, m;
vector<int> adj[maxN];
int depth[maxN];
int up[logN][maxN];

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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("PEACE.INP", "r", stdin);
    freopen("PEACE.OUT", "w", stdout);
    cin >> n >> m;
    for (int i=1; i<n; i++)
    {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,1);
    while (m--)
    {
        int z, x, y; cin >> z >> x >> y;
        int a=lca(x, y);
        if (lca(z, a)!=a)
        {
            cout<<a<<endl;
        }
        else
        {
            cout<<(lca(z,x)^lca(z, y)^a)<<endl;
        }
    }
}

