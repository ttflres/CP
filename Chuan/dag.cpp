#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+7;

int n, m;
vector<int> g[maxn];
int d[maxn];
bool flag=true;

void dfs(int x)
{
    d[x]=1;
    for (auto u:g[x])
    {
        if (d[u]==1)
        {
            // cout<<"NO";
            flag=false;
            return;
        }
        else if (d[u]==0) dfs(u);
    }
    d[x]=2;
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("nhapinput.inp", "r", stdin);
    freopen("nhapoutput.out", "w", stdout);
    #endif
    cin >> n >> m;
    for (int i=1; i<=m; i++)
    {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
    }
    for (int i=1; i<=n; i++)
    {
        if (!d[i]) dfs(i);
    }
    if (flag) cout<<"YES";
    else cout<<"NO";
}