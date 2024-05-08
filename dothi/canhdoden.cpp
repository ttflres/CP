#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e5+7;
const int mod=1e9+7;

int power(int a, int b, int mod)
{
    if (b==0) return 1;
    int t=power(a, b/2, mod);
    t=(t*t)%mod;
    if (b&1) return (t*a)%mod;
    return t%mod;
}

int n, k;
int cnt;
vector<int> g[maxn];
int d[maxn];

void dfs(int u)
{
    cnt++;
    d[u]=1;
    for (auto x:g[u]) if (!d[x]) dfs(x);
}

signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);
   cin >> n >> k;
   for (int i=1; i<=n-1; i++)
   {
       int a, b, c; cin >> a >> b >> c;
       if (c==0)
       {
           g[a].push_back(b);
           g[b].push_back(a);
       }
   }
   int ans=power(n, k, mod);
   for (int i=1; i<=n; i++)
   {
       if (!d[i])
       {
           cnt=0;
           dfs(i);
           ans-=power(cnt, k, mod);
           ans+=mod;
           ans%=mod;
       }
   }
   cout<<ans;

}
