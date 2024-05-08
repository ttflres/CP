#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+7;

int n, d[maxn], mx=-1, node;
vector<int> g[maxn];

void dfs(int x, int dd)
{
    d[x]=1;
    if (dd>mx)
    {
        mx=dd;
        node=x;
    }
    for (auto u:g[x])
    {
        if (!d[u])
        {
            dfs(u, dd+1);
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("nhapinput.inp", "r", stdin);
    freopen("nhapoutput.out", "w", stdout);
    #endif
    cin >> n;
    for (int i=1; i<n; i++)
    {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, 0);
    mx=-1;
    for (int i=1; i<=n; i++) d[i]=0;
    dfs(node, 1);
    cout<<mx-1;

}