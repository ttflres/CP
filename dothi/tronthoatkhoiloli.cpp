#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e5+7;

int n, m, k;
int a[maxn], d[maxn], vis[maxn];
vector<int> g[maxn];

void bfs(int x)
{
    queue<int> q;
    q.push(x);
    vis[x]=1;
    while (!q.empty())
    {
        int u=q.front();
        q.pop();
        for (auto v:g[u])
        {
            if (vis[v]==0)
            {
                vis[v]=1;
                d[v]=d[u]+1;
                q.push(v);
            }
        }
    }
}

signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);
   cin >> n >> m >> k;
   for (int i=1; i<=k; i++) cin >> a[i];
   for (int i=1; i<=m; i++)
   {
       int u, v; cin >> u >> v;
       g[u].push_back(v);
       g[v].push_back(u);
   }
   int cnt=0;
   bfs(n);
   for (int i=1; i<=k; i++)
   {
       if (d[a[i]]<=d[1]) cnt++;
   }
   cout<<cnt;

}
