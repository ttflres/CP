#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int maxn = 1e5 + 7;
int n, m;
vector<int> g[maxn];
int d[maxn];
bool k=true;
void dfs(int u)
{
    d[u]=1;
    for (auto x:g[u])
    {
        if (d[x]==0)
        {
            dfs(x);
        }
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i=1; i<=m; i++)
        {
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        dfs(1);
    for (int i=1; i<=n; i++)
    {
        if (d[i]==0)
        {
            k=false;
        }
    }
    if (!k||m!=n-1) cout<<"No";
    else cout<<"Yes";
}
