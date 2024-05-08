#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+7;

int n, d[maxn];
vector<int> g[maxn], side(maxn, -1);
bool ok=true;

void bfs(int x)
{
    queue<int> q;
    if (side[x] == -1) {
        d[x]=1;
        q.push(x);
        side[x] = 0;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int u : g[v]) {
                if (side[u] == -1) {
                    d[u]=1;
                    side[u] = side[v] ^ 1;
                    q.push(u);
                } else {
                    ok &= side[u] != side[v];
                }
            }
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while (t--)
    {
    cin >> n;
    for (int i=1; i<=n; i++) g[i].clear(), side[i]=-1;
    memset(d, 0, sizeof(d));
    for (int i=1; i<=n; i++)
    {
        int p; cin >> p;
        for (int j=1; j<=p; j++)
        {
            int x; cin >> x;
            g[x].push_back(i);
            g[i].push_back(x);
        }
    }
    int ans=0;
    for (int i=1; i<=n; i++)
    {
        if (!d[i])
        {
            for (int i=1; i<=n; i++) side[i]=-1;
            ok=true;
            bfs(i);
            int cnt0=0, cnt1=0;
            if (ok)
            {
            for (int i=1; i<=n; i++)
            {
                // cout<<side[i]<<" ";
                if (side[i]==1) cnt1++;
                else if (side[i]==0) cnt0++;
            }
            ans+=max(cnt1, cnt0);
            }

        }
    }
    cout<<ans<<endl;
    }
}
