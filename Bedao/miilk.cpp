#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e5+7;

int n, m, k;
int u[maxn], v[maxn], o[maxn], w[maxn];
int d[maxn], mt[maxn], ans[maxn];
vector<pair<int, int>> g[maxn];

void dijkstra()
{
    priority_queue<pair<int, int>> pq;
    memset(ans, 0x3f, sizeof(ans));
    memset(d, 0x3f, sizeof(d));
    for (int i=1; i<=k; i++)
    {
        int p, t; cin >> p >> t;
        mt[p]=t;
        o[p]=p;
        d[p]=0;
        pq.push({-d[p], p});
    }
    while (pq.size())
    {
        int w=-pq.top().first, u=pq.top().second;
        pq.pop();
        if (d[u]!=w) continue;
        for (auto x:g[u])
        {
                if (d[x.first]>d[u]+x.second)
                {
                    d[x.first]=d[u]+x.second;
                    o[x.first]=o[u];
                    pq.push({-d[x.first], x.first});
                }
        } 
    }
}

signed main() {
    freopen("milktea.inp", "r", stdin);
    freopen("milktea.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    for (int i=1; i<=m; i++)
    {
        cin >> u[i] >> v[i] >> w[i];
        g[u[i]].push_back({v[i], w[i]});
        g[v[i]].push_back({u[i], w[i]});
    }
    dijkstra();
    for (int i=1; i<=n; i++)
    {
        if (!mt[i]) ans[i]=d[i];
    }
    for (int i=1; i<=m; i++)
    {
        if (o[u[i]]!=o[v[i]])
        {
            ans[o[u[i]]]=min(d[u[i]]+d[v[i]]+w[i], ans[o[u[i]]]);
            ans[o[v[i]]]=min(d[u[i]]+d[v[i]]+w[i], ans[o[v[i]]]);
        }
    }
    for (int i=1; i<=n; i++) cout<<ans[i]<<" ";
}

