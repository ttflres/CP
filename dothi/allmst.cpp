    #include<bits/stdc++.h>
    using namespace std;
    #define int long long

    const int maxn=2e5+7;

    struct edge
    {
        int u, v, w, id;
        bool operator < (const edge &o) const {
            return w < o.w;
        }
    }edges[maxn];

    struct dsu
    {
        vector<int> p;

        void init(int n)
        {
            p.resize(n+5, 0);
            for (int i=1; i<=n; i++) p[i]=i;
        }

        int find(int u)
        {
            if (p[u]==u) return u;
            else return p[u]=find(p[u]);
        }

        bool yoin(int u, int v)
        {
            u=find(u), v=find(v);
            if (u==v) return false;
            p[v]=u;
            return true;
        }

    } DSU;

    vector<pair<int, int>> g[maxn];
    int low[maxn], num[maxn], cnt=0;
    int n, m;
    int res[maxn];

    void dfs(int u, int idx)
    {
        low[u] = num[u] = ++cnt;
        for (auto x : g[u]) {
            int v = x.first, id = x.second;
            if (id == idx) convtinue;
            if (num[v]) {
                low[u] = min (low[u],num[v]);
            }
            else {
                dfs (v,id);
                low[u] = min (low[u],low[v]);
                if (low[v] >= num[v]) {
                    res[edges[id].id] = true;
                }
            }
        }
    }

    void solve(vector<edge> &pen) {
        if (pen.empty()) return;
        // noi cac tplt
        for (int i = 0; i < pen.size(); i++) {
            // dsu lam dai dien
            pen[i].u = DSU.find(pen[i].u); pen[i].v = DSU.find(pen[i].v);
            g[pen[i].u].clear(); g[pen[i].v].clear();
            num[pen[i].u] = num[pen[i].v] = 0;
        }
        for (auto e : pen) {
            if (e.u == e.v) continue;
            else {
                // noi 2 tplt
                res[e.id]=0;
                g[e.v].push_back({e.u, e.id});
                g[e.u].push_back({e.v, e.id});
            }
        }

        // tim cc
        for (auto &e : pen) if (num[e.u] == 0) dfs(e.u, -1);
        // hop cc
        for (auto &e : pen) DSU.yoin(e.u, e.v);
    }

    signed main()
    {
       ios_base::sync_with_stdio(false);cin.tie(NULL);
       cin >> n >> m;
       DSU.init(n);
       for (int i=1; i<=m; i++)
       {
           int U, V, W;
           cin >> U >> V >> W;
           edges[i].u=U, edges[i].v=V, edges[i].w=W;
           edges[i].id=i;
       }
       sort(edges+1, edges+m+1);
       vector<edge> pen;
        for (auto &e : edges) {
            if (!pen.empty() && pen.back().w == e.w) {
                pen.push_back(e);
            }
            else {
                solve(pen);
                pen = {e};
            }
        }
        solve(pen);
        for (int i = 1; i <= m; i++) {
            if (res[i]) cout<<"Yes ";
            else cout<<"No ";
        }
    }
