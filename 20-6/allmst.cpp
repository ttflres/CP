#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> ii;
#define x first
#define y second
struct Data
{
    int u, v, w, id;
};
const int N = 3e5 + 1;
int n, m, par[N], d[N], up[N][20], mi[N][20];
Data a[N];
vector<ii> ans[N];
bool check[N];
long long res = 0;
int last[N];
bool cmp(Data a, Data b)
{
    return a.w < b.w;
}
int find(int u)
{
    if (!par[u])
        return u;
    return par[u] = find(par[u]);
}
void make_tree()
{
    sort(a + 1, a + m + 1, cmp);
    for (int i = 1; i <= m; i++)
    {
        int x = a[i].u;
        int y = a[i].v;
        int w = a[i].w;
        int u = find(x);
        int v = find(y);
        if (u == v)
            continue;
        res += w;
        par[v] = u;
        ans[x].push_back({y, w});
        ans[y].push_back({x, w});
    }
}
void dfs(int u)
{
    for (ii e : ans[u])
    {
        int v = e.x;
        int w = e.y;
        if (up[u][0] != v)
        {
            up[v][0] = u;
            mi[v][0] = w;
            d[v] = d[u] + 1;
            for (int i = 1; i < 20; i++)
            {
                int temp = up[v][i - 1];
                up[v][i] = up[temp][i - 1];
                mi[v][i] = max(mi[v][i - 1], mi[temp][i - 1]);
            }
            dfs(v);
        }
    }
}
int lca(int u, int v)
{
    int maxn = 0;
    if (d[u] != d[v])
    {
        if (d[u] < d[v])
            swap(u, v);
        int k = d[u] - d[v];
        for (int i = 0; (1 << i) <= k; i++)
            if (k >> i & 1)
                maxn = max(maxn, mi[u][i]), u = up[u][i];
    }
    if (u != v)
    {
        int lg = __lg(d[u]);
        for (int i = lg; i >= 0; i--)
            if (up[u][i] != up[v][i])
            {
                maxn = max({maxn, mi[v][i], mi[u][i]});
                u = up[u][i];
                v = up[v][i];
            }
        maxn = max({maxn, mi[v][0], mi[u][0]});
    }
    return maxn;
}
void nhap()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> a[i].u >> a[i].v >> a[i].w, a[i].id = i;
}
void xuly()
{
    make_tree();
    dfs(1);
    for (int i = 1; i <= m; i++)
        last[a[i].id] = res - lca(a[i].u, a[i].v) + a[i].w;
    for (int i = 1; i <= m; i++)
        cout << last[i] << "\n";
}
signed main()
{
    ios_base::sync_with_stdio(NULL), cin.tie(NULL);
    nhap();
    xuly();
    return 0;
}
