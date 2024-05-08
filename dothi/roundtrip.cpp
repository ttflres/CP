#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=2e5+7;

int n, m;
vector<int> g[maxn], ans;
int d[maxn];

void dfs(int x, int p)
{
    for (auto u:g[x])
    {
        if (u==p) continue;
        if (d[u])
        {
            ans.push_back(x);
            while (ans.back()!=u)
            {
                ans.push_back(d[ans.back()]);
            }
            ans.push_back(x);
            cout<<ans.size()<<endl;
            for (auto i:ans) cout<<i<<" ";
            exit(0);

        }
        d[u]=x;
        dfs(u, x);
    }
}

signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);
   cin >> n >> m;
   for (int i=1; i<=m; i++)
   {
       int a, b; cin >> a >> b;
       g[a].push_back(b);
       g[b].push_back(a);
   }
   for (int i=1; i<=n; i++)
   {
       if (!d[i])
       {
           d[i]=i;
           dfs(i, 0);
       }
   }
   cout<<"IMPOSSIBLE";
}
